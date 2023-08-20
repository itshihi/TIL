### 핵심개념
---
1. 클래스
: 함수를 포함할 수 있는 구조체의 확장
2. 생성자와 소멸자
: 클래스 객체가 생성 및 소멸할 때 '자동으로' 호출되는 함수
3. 메서드
: 함수 형태로 클래스의 실제 동작과 상태를 책임진다. 실제로 어떤 동작을 구현하는 데 가장 중심이 된다.

<b>

### 1. 개요
"객체란 변수들과 그와 관련된 메서드들이 모여서 이룬 하나의 꾸러미다."
"클래스란 C의 구조체에서 확정된 변수, 객체, 함수

<b>

### 2. 기본 문법
"함수를 포함할 수 있는 구조체"
```cpp
class 클래스 이름{
    접근제어지시자;
        멤버변수선언;
        멤버함수선언및정의;
}

class USERDATA{
public:
    int nAge;
    char szName;

    void Print(void){
        cout << nAge << szName <<
    }
}
```
<b>


### 3. 접근 제어 지시자
제작자 스스로 자신이 만든 클래스의 특정 요소에 사용자가 접근할 수 없도록 private, public, protected 접근 제어 지시자를 사용한다.

<br>

지시자|설명
---|---
public|멤버에 관한 모든 외부 접근이 불가능
protected|멤버에 관한 모든 외부 접근이 불가능<br> 단, 상속 관계에 있는 파생 클래스에서의 접근은 허용
public|멤버에 관한 모든 외부 접근 가능

- 세가지 중 private이 기본 지시자로 별도로 언급하지 않는다면 기본적으로 private이 적용
<br>


```cpp
// 제작자 코드
class CMYData{

    // 클래스 멤버변수 선언
    // 기본 접근 제어 지시자는 'private'
    int m_nData;

public:
    int GetData(void){return m_nData;}
    void SetData(int nParam){m_nData=nParam;}
};


int main(){
    CMYData data;

    //m_nData는 private 멤버 변수이므로 액세스할 수 없다 
    // data.m_nData = 20; 

    //public 멤버 함수인 SetData()를 통해 변수값 할당
    data.SetData(10);
    cout << data.GetData();
}
```
- 생성자도 접근 제어 지시자의 영향을 받는다.
```cpp
class CMYData{
    CMYData(){}; // 생성자를 private으로 선언
public:
...
}

int main(){
    CMYData mydata; //error "CMYData::CMYData()" (declared at line 49) is inaccessible
}
```
<b>


### 4. 생성자와 소멸자
Constructor와 Destructor는 클래스 객체가 생성 및 호출될 때 '자동으로' 호출되는 함수
- main()함수가 호출되기 전에 전역변수로 선언한 클래스의 생성자가 호출될 수 있다.
- 생성자는 다중 정의할 수 있고, 동시에 여러 개가 존재할 수 있다.
- 소멸자는 다양성이 없으므로 다중 정의되지 않는다.
- main()함수가 끝난 후에 소멸자가 호출될 수 있다.
- 생성자와 소멸자는 생략될 수 있으나 생략할 경우 컴파일러가 만들어 넣는다(즉, 생성자, 소멸자가 없는 클래스는 없음).

``` cpp
class CTest{

    int m_nData;

public:

    // 생성자     
    CTest(int nParam):m_nData(nParam){
        cout << "CTest::CTest()     " << m_nData<<endl;
    }

    void setDate(){cout << m_nData << endl;}

    ~CTest(){cout << "~CTest::CTest()   "<<m_nData<<endl;};
};


CTest a(10);
int main(){
    cout << "Begin" << endl;
    CTest b(20);
    cout << "End" << endl;

}
```
```cpp
// 실행 결과
CTest::CTest()     10
Begin
CTest::CTest()     20
End
~CTest::CTest()   20 // 나중에 선언한 클래스 소멸자가 먼저 등장
~CTest::CTest()   10
```

<b>

### 3.1 동적 객체의 생성과 소멸

```cpp
class CTest{
    int m_nData; // 클래스 전역 변수
public:

// 생성자
 CTest(){
    cout << "CTest::CTest()" << endl;
 }

//소멸자
~CTest(){
    cout << "~CTest::CTest()" << endl;
}
};
```

- CTest 를 동적으로 생성, 소멸했을 때, delete 선언 시 즉각적으로 소멸자 호출된다.
- 즉, new와 delete 연산자는 각각 생성자와 소멸자를 호출한다.

```cpp
int main(){

    cout << "BEGIN" << endl;

    // new 동적 할당 연산자로 CTest 객체 생성
    CTest *ctest = new CTest;

    cout << "TEST" << endl;

    delete ctest;

    cout << "END" << endl;
}
```
```cpp
// 실행결과
BEGIN
CTest::CTest()
TEST
~CTest::CTest()
END
```
- CTest 객체를 지역 변수로 선언했을 때
```cpp
BEGIN
CTest::CTest()
TEST
END
~CTest::CTest()
```

> 이 때 배열로 생성한 객체들은 반드시 배열로 삭제해야한다.
> 배열로 생성한 객체를 배열로 삭제하지 않는다면 첫 번째 요소만 소멸하고 나머지는 그대로 메모리에 남는다.(메모리 릭 버그)

### 3.2 참조 형식 멤버 초기화
- 참조형 멤버 변수가 있을 시, 생성자 초기화 목록으로 초기화 해야한다.

```cpp
class CRefTest{

public:

    // 참조형 멤버는 반드시 생성자 초기화 목록을 통해 초기화
    CRefTest(int &rParam) : m_nData(rParam){ cout << "m_nData value is " << rParam << endl;};
    int GetData(){ return m_nData; };

private:
    // 참조형 멤버는 객체가 생성될 때(생성자 선언시) 반드시 초기화 해야한다.
    int &m_nData;
};

int main(){

    int a=10;
    CRefTest t(a);

    cout << t.GetData();
}
```
- 생성자에서 매개변수를 참조자로 받지 않으면, 함수의 매개변수는 함수 내부의 자동변수와 같으므로 함수가 반환될 때 매개변수는 소멸된다.

<br>

### 3.3 생성자의 다중 정의
- 생성자가 다중 정의될 경우 사용자는 편하겠지만, 제작자는 동일한 멤버를 초기화하는 코드를 여러번 기술해야 하는 번거로움이 있음
```cpp
class CMyData{
public:

    // 디폴트 생성자는 없음
    // 매개변수가 하나인 생성자 함수 정의 및 선언
    CMyData(int nParam) : m_nData(nParam){};
    
    // 매개변수가 두개인 생성자 함수 정의 및 선언
    CMyData(int x, int y) : m_nData(x+y){};

    int GetData(void){return m_nData;}


private:
    int m_nData;
};
```
- '생성자 위임'을 이용하면 생성자 초기화 목록에서 다른 생성자를 추가로 부를 수 있음

```cpp
class CMyPoint{

public:

    CMyPoint(int x){
        cout << "CMyPoint(int)" << endl;

        // if(x>10){
        //     x=100;
        // }
        m_x = 100;

    }

    CMyPoint(int x, int y)
    // x값을 검사하는 코드는 이미 존재하므로 초기화 목록으로 재사용한다!
    : CMyPoint(x){
        cout << "CMyPoint(int, int)" << endl;

        // if(y>200){
        //     y=200;
        // }
        m_y=200;
    }
};
```















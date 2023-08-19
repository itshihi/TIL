### 핵심개념
---
1. 클래스
: 함수를 포함할 수 있는 구조체의 확장
2. 생성자와 소멸자
: 클래스 객체가 생성 및 소멸할 때 '자동으로' 호출되는 함수
3. 메서드
: 함수 형태로 클래스의 실제 동작과 상태를 책임진다. 실제로 어떤 동작을 구현하는 데 가장 중심이 된다.


### 1. 개요
"객체란 변수들과 그와 관련된 메서드들이 모여서 이룬 하나의 꾸러미다."
"클래스란 C의 구조체에서 확정된 변수, 객체, 함수

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





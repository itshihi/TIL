

### 1. 
#### #include < iostream >

- iostream은 확장명은 없지만, 분명한 헤더 파일이다.
iostream.h 와는 다른 파일로, 확장자가 생략된 이유는 `C++에서는 사용자 정의 헤더 파일이 아닌 표준 헤더 파일들은 모두 .h 확장명을 생략하기 때문이다.`
- C에서의 <stdio.h> 와 같은 역할을 한다.



### 2.
```cpp
std::cout << "Hello World!" << std::endl;
```
- std는 'namespace'라고 하며 개념 상 `소속`으로 생각하면 쉽다.
- :: 는 `범위 지정 연산자` 혹은 스코프 설정 연산자
- cout은 콘솔 출력을 담당하는 객체이다.
- << '연산자 함수'이다.

- std::endl 은 c의 '\n'처럼 개행 역할과 출력 스트림 모두를 내보내는 역할을 동시에 수행

<br>

### 3.
#### 인스턴스와 입출력의 흐름

```cpp
사람 철수, 영희;
```
철수와 영희는 각각 사람이라는 형식에 대한 인스턴스이다.

즉, 
```cpp
int a;
string b;
```
a는 자료형에 대한 인스턴스이고, b는 string 자료형에 대한 인스턴스다.

OPP 환경에선 모든 것을 다 객체(사람, int, string...)로 표현하고 객체의 형식을 갖는 것을 인스턴스라고 한다.

<br>

### 4.
#### 변수 선언
```CPP
int a = 10;
```
혹은,
```cpp
int a(10);
int b(a);
```
10은 int 자료형 인스턴스인 a의 초깃값이 된다.
뒤의 b는 초기값이 상수가 아닌 변수 a가 된다.
즉, b는 a를 복사해서 만들어진다. -> 복사생성자로 이어지는 개념



#### 자료형 auto
- auto를 사용하면 변수의 자료형을 명시적으로 선언하지 않아도 된다.

- `초깃값 형식에 맞춰 선언하는 인스턴스의 형식이 '자동`으로 결정된다.

- 즉, 변수가 초기화 값으로부터 자료형을 추론하므로 초기화 과정이 꼭 필요하다.

<br>

### 5.
메모리 동적 할당

#### new와 delete 할당자
객체를 동적 할당하고 해제하는 `연산자`이다.

```cpp
형식 *변수이름 = new 형식;
delete 변수이름;
```
배열의 경우,
```cpp
형식 *변수이름 = new 형식[요소개수];
delete[] 변수이름;
```
- new 연산자를 사용하면, `메모리 크기를 정하지 않는다.`

- 여기서 유의할 점은 `배열 형태로 동적 생성한 것은 반드시 배열 형태를 통해 삭제`해야 한다는 것이다.

- 그렇지 않으면 `메모리 누수`(memory leak)가 발생한다. 프로그램이 실행되는 동안 미모리가 해제되지 않고 계속 남아있는 상태인 것이다. -> 메모리 사용량이 점차 증가되어 프로그램의 성능 저하 및 충돌로 이어질 수 있음

```cpp
int* arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = (i + 1) * 10;
    }

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }


    // 배열 형태로 생성한 대상은 반드시 배열 형태로 삭제한다.
    delete[] arr;
```

[정리]
"new 연산자는 객체의 생성자를 호출하고, delete 연산자는 객체의 소멸자를 호출한다."

<br>


### 6. 참조자(Reference)
- 다음과 같이 생성과 동시에 초기화를 해주어야한다.
```cpp
형식 &이름 = 원본;
```

- 포인터와 마찬가지로 상수엔 참조자를 선언할 수 없다.

```cpp
    int nData = 10;

    //nData 변수에 대한 참조자 선언
    int& ref = nData;
    cout << ref << endl; // 10
    
    // 참조자의 값을 변경하면 참조 원본(nData)도 변경된다.
    ref = 20;
    cout << ref; // 10 20

    // 포인터에 참조자 할당
    int* pnData = &nData;
    * pnData = 30;
    cout << nData; // 30

```

- 즉, 포인터와 참조의 원리는 내부 구조상으로 같다.
- 함수를 호출할 때 매개변수로 주소를 전달하는 기법을 '참조에 의한 호출' (Call by Reference)라 하는데, 여기서 reference는 '주소'를 의미한다.

- `덩치 큰 자료는 값이 아닌 '주소(참조)'를 전달하는 것이 효율적이다!`

```cpp

// 매개변수가 int 자료형의 참조자이다.
void TestFunc(int& rParam) {

    // 피호출자 함수에서 원본의 값을 변경했다.
    // 피호출자란 실제로 호출이 일어나는 함수를 의미
    rParam = 100; 
}
```
- 함수의 매개변수가 참조자인 경우 가장 큰 문제점은 호출자 코드만 봐서는 매개변수가 참조 형식이라는 사실을 알 수 없다는 것이다.

```cpp
void Swap(int a, int b){
    int nTemp = a;
    a = b;
    b = nTemp;
}

int main(){
    int a(10), b(20);

    Swap(a,b); // Swap 함수에 a와 b 복사본이 전달됨
    // 즉 원본 변수 a와 b엔 영향없다 -> 참조자를 사용해야하는 이유!
}
```
<br>

### 7. 
#### 범위 기반 for 문

- for문은 보통 일정 '횟수' 중심으로 반복되고, while문은 조건을 중심으로 반복된다.
- 배열 자료구조에 접근할 때 for문을 자주 사용하는데, 이는 배열의 요소가 선언할 때 확정되기 때문이다.
-> 여기서 만일 배열의 요소 개수를 변경한다면?

당연히 for문도 수정해야한다.

```cpp
    for(auto 요소변수: 배열이름)
        반복 구문;
```
- 다음과 같이 `반복 횟수는 배열의 요소 개수에 맞춰 자동으로 결정` 된다.

```cpp
    int aList[5] = { 10, 20, 30, 40, 50 };

    // 전형적인 C스타일
    for (int i = 0; i < 5; i++) {
        cout << aList[i] << "   ";
    }

    // n은 aList의 요소변수
    for (auto n : aList)
        cout << n << ' ';

    cout << endl;


    // n은 각 요소에 대한 참조자
    for (auto& n : aList)
        cout << n << "  ";

```
- C 스타일 반복문의 경우 aList의 요소 개수가 바뀌면 조건식을 반드시 수정해야한다.

- auto 를 이용해 범위 기반 for 문 이용시엔 무관함!




#include<iostream>
#include<algorithm>
using namespace std;

// 주어진 길이 N의 int 배열 arr에서 
// 합이 100인 서로 다른 위치의 두 원소가 존재하면 1을
// 존재하지 않으면 0을 반환하는 함수 func2(int arr[], int N)을 작성하라.
// arr의 각 수는 0 이상, 100 이하이고 N은 1000 이하이다.


int func2(int arr[], int n){

//내 풀이
    // for반복문 arr 길이만큼
    // for문으로 100짜리 배열 중 유효한 원소에 1 표시한다.
    // for문 으로 i 번째 원소와 100-i 번째 원소가 존재하는 경우/ i=0; i<n

    int base[100];
    fill(base, base+100, 0); //전체값 0으로 초기화


// 한 번의 for문으로 arr[i]++ 와 100-arr[i] 값이 존재하는지 확인까지 처리함
    for(int i=0; i<n; i++){
        if(base[100-arr[i]]){
            return 1;
        }
        base[arr[i]]++;
    }

    return 0;

// sol
    // int occur[101]={};
    // fill(occur, occur+101, 0);

    // for(int i=0; i<n; i++){
    //     if(occur[100-arr[i]]==1){
    //         return 1;
    //     }
    //     occur[arr[i]] = 1;
    // }
    // return 0;
}

int main(){
    int arr[] = {1, 52, 48};
    int arr2[] = {50, 42};
    int arr3[] = {4, 13, 63, 87};

    cout << func2(arr, 3) << "\n"; //1
    cout << func2(arr2, 2)<< "\n"; //0
    cout << func2(arr3, 4); //1
}
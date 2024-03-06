#include<iostream>
#include <cstring>
#include<algorithm>
using namespace std;

int main(){
    int a[21];
    int b[21][21];

    //1. memeset
    // memset(a, -1, sizeof a);
    // memset(b, 0, sizeof a);


    //3. fill
    fill(a, a+21, 0);


    for(int i=0; i<21; i++){
        fill(b[i],b[i]+21, 0);
    }

    
    for(int i=0; i<21; i++){
        for(int j=0; j<21; j++){
            cout << b[i][j] << " ";
        }
    }





}
#include<iostream>
#include<vector>

using namespace std;

int solution(int n){ // 인원 수

    int answer = 0; //피자 판 수
    int temp, k(6);
    int p = n; 

    // 
    // 최대 공약수  n, k=6, temp
    // 

    while(k!=0){
        // cout << n <<"   " << k << "  " << temp << "     ";
        
        temp = p%k;
        p = k;
        k = temp;
        
        // cout << n <<"   " << k << "  " << temp <<endl;
        

    }

    answer = n/p;


    return answer;

}

int main(){    

    cout << solution(15) << endl; // 15, 6  3
    cout << solution(4) << endl; 

    

    


}
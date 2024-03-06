#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v1 = {1,2,3,4,5,6};
    
    //1. range-based for loop
    for(int e:v1){
        cout << e << " ";
    }

    cout << "\n";

    //2. not bad
    for(int i=0; i<v1.size(); i++){
        cout << v1[i] << " ";
    }


}
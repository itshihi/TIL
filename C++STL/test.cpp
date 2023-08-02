// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;


// int main(){
//     vector<int> ex(5,0);
//     int age = 25;

//     // vec.insert(vec.begin(),0);

//     // for(int i = 0; i<size(vec); i++){
//     //     cout << vec[i] << "     ";
//     // }

//     // cout << "\n---------------\n";

//     // vec.insert(find(vec.begin(), vec.end(), 1), 4); // 1 "앞에" 4 추가

//     vector<int> vec = {2,4,1,3,2};

//     // for(vector<int>::iterator it = vec.begin(); it!=vec.end(); ++it){
        
//     //     cout << *it << " ";
//     // }

//     // cout << vec.begin() << " ";

//     for(int i = 0; i<size(vec); i++){
//         cout << vec[i] << "     ";
//     }

//     cout << "\n---------------\n";

//     // vec.pop_back();
//     vec.erase(vec.begin(), vec.begin()+1);

//     // for(int i = 0; i<size(vec); i++){
//     //     cout << vec[i] << "     ";
//     // }

//     cout << vec.size() << "  " << vec.capacity() << endl;
//     vec.reserve(9);
//     cout << vec.size() << "  " << vec.capacity() << endl;



// } 



#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class MyAllocator {
public:
    using value_type = T;

    MyAllocator() = default;

    T* allocate(std::size_t n){
        std::cout<<"MyAllocator: Allocating " << n << " elements. " << std::endl;
        return static_cast<T*>(::operator new(sizeof(T) * n))
    }
};
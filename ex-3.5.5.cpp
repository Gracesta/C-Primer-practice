#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main(){
    int array[5] = {0, 1, 2, 3, 4};
    int arr2[3];
    vector<int>ivec(begin(array)+1, end(array)-1);
    int i =0;
    for(auto it = ivec.begin();it!=ivec.end();it++){
        cout << *it << endl;
        arr2[i++] = *it;
    }
    for(size_t x : arr2){
        cout << x << endl;
    }
}

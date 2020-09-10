#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

using namespace std;



int main(){
    // int t=2, x=5;
    // cout << [t](int x)->int{ return t+x;}(10) << endl;
    vector<int> vec(3,-1);
    int x =2;
    auto back = back_inserter(vec);
    fill_n(back, 2,-2);
    transform(vec.begin(), vec.end(),vec.begin(), [x](int i){if(i<0) return -i+x; else return i+x;});
    for(auto &x : vec)
        cout << x << " ";
    return 0;
}
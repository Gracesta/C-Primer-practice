#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    vector<int> vec;
    auto back_it = back_inserter(vec); // even though back inserter will change the capacity of Container,
    fill_n(back_it, 10, 1);            // this one belongs to header <iterator>, so "algorithm" doesn't change its capacity
    fill_n(begin(vec), vec.size(), 0);
    for(auto it = begin(vec);it != end(vec);++it){
        cout << *it << " ";
    }

    string s = "123";
    cout << 1+stoi(s.substr(1,2)) << endl;
    return 0;
}
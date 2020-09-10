#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    string s = "Where there is a will.";
    for(auto &p: s)
        cout << typeid(p).name() << endl;
    return 0;
}
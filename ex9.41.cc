#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<char> vec{'H','e','r','e','i','s'};
    string str;
    str.reserve(100);
    cout << str.capacity();
    return 0;
}
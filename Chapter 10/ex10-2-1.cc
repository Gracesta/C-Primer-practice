#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    vector<double> vec{1.1,1.1,1,2,3,4,5.5,10,10};
    cout << accumulate(begin(vec), end(vec), static_cast<double>(-1)) << endl;//the ype of output based on the 3rd paramater
    
    string str = "Where there is a will, there is a way.";
    cout << accumulate(begin(str), begin(str)+4, string(""))<<endl;

    char str1[5]={"bcde"};
    char str2[5]={"bcde"};
    cout << equal(str1, str1+5, str2);

    return 0;
}
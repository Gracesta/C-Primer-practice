#include <iostream>

using namespace std;

int main(){
    int i, j;
    cout << "input two numbers to get the qualification:"<< endl;
    while(cin >> i >> j){
        try{
            if(j == 0){
                throw runtime_error("can't be dvided by 0");   
            }
            cout << (static_cast<double>(i)/j) << endl;
        }catch(runtime_error re){
            cout << re.what() << endl;
        }
    }
}
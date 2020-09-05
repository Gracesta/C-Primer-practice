#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(){
    list<int> lst{0,1,2,3,4,5};
    auto it = lst.begin();
    lst.insert(it, -1);
    cout << *++it << endl;
    return 0;
}
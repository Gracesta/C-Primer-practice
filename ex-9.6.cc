#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> lst1;
    lst1.push_back(1);
    lst1.push_back(2);
    list<int>::iterator iter1 = lst1.rbegin(),
            iter2 = lst1.end();
    while(iter1 != iter2)
        cout << 'y' << endl;
        cout << "finished" << endl;
    return 0;
}
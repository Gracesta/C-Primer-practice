#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

using array_int = int[4]; 

int main(){
    int ia[3][4]= {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    //Version 1

    for( array_int &row : ia){              // int (&row)[4]
        for(int &col : row){
            col++;
            cout << col << "\t ";
        }
        cout << endl;
    }


    //Version 3

    for(array_int *i = begin(ia);i!= end(ia);i++){          // int (*p)[4]
        for(int *j = begin(*i);j!=end(*i);j++){
            cout << *j << "\t";
            //cout <<typeid(i).name()<<endl;
        }
        cout << endl;
    }
    
}
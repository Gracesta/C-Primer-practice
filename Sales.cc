#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

struct Sales_data{
    string bookNo;
    unsigned units_sold = 0;
    double revenue=0.0;

    string isbn() const{
        return bookNo;
    }
    Sales_data& combine(const Sales_data &rhs) {
        this->units_sold += rhs.units_sold;
        this->revenue += rhs.revenue;
        return *this;
    }
};

struct Person{
    string name;
    string address;
    const string getName(){ return name;}
    const string getAddress(){ return address;}
};

istream &read(istream &is, Sales_data &item){
    double price =0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item){
    os << item.bookNo << " "<< item.units_sold << " "<<item.revenue;
    return os;
}

Sales_data &add(Sales_data &lhs, const Sales_data &rhs){
    Sales_data sum = lhs;
    return sum.combine(rhs);
}

int main(){
    Sales_data a, b;
    read(read(cin, a), b);;
    Sales_data total = add(a,b);
    print(cout, total) << endl;
    print(cout, a) << endl;
    return 0;
}
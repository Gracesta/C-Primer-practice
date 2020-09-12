#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

using namespace std;


struct Sales_data{
friend istream &read(istream &is, Sales_data &s);
friend ostream &print(ostream &os, const Sales_data &s);

public:
    string isbn() const{
        return bookNo;
    }
    Sales_data& combine(const Sales_data &rhs) {
        this->units_sold += rhs.units_sold;
        this->revenue += rhs.revenue;
        return *this;
    }

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue=0.0;
};

class Person{

friend istream &read(istream &is, Person &p);
friend ostream &print(ostream &os, const Person &p);

public:
    const string getName(){ return name;}
    const string getAddress(){ return address;}
    Person() = default;
    Person(istream &is){
        getline(is, name);
        getline(is, address);
    }
    Person(string n, string ad):name(n), address(ad){}
private:
    string name;
    string address;
};

istream &read(istream &is, Person &p){
    getline(is, p.name);
    getline(is, p.address);
    return is;
}

ostream &print(ostream &os, const Person &p){
    os << p.address << " "<< p.name;
    return os;
}

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
    // Sales_data a, b;
    // read(read(cin, a), b);;
    // Sales_data total = add(a,b);
    // print(cout, total) << endl;
    Person p("M", "t");
    print(cout, p);
    //read(cin, p);
    Person t(cin);
    print(cout, t);
    return 0;
}
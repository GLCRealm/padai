#include<iostream>
using namespace std;

class A{
    public:
    // here we use virtual class
    void virtual x(){
        cout<<1<<endl;
    }
};

class B:public A{
    public:
    // here he created virtual class
    void virtual x(){
        cout<<2<<endl;
    }
};

int main(){

    cout<<"Here is the example of runtime polymorphism and use of virtual function:-\n"<<endl;
    A* ptr=new B(); // here we created a pointr ptr of class A type pointingto class B
    ptr->x();
    cout<<"\nBecause of early binding without using virtual function 1 will print.\nSince we used virtual function late binding will happen."<<endl;
}
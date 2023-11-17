#include <iostream>
using namespace std;

class A{

    public:
    int a1=1;
    int a2=2;

};

class B:virtual public A{

    public:
    int b1=3;
    int b2=4;
    
};

class C:virtual public A{

    public:
    int c1=5;
    int c2=6;
    
};

class D:public B,public C{

    public:
    int d1=7;
    int d2=8;
    
};

int main(){

    D obj;

    cout<<obj.b1<<endl;
    cout<<obj.d1<<endl;
    cout<<obj.c1<<endl;
    
    cout<<obj.a1<<endl; //this is error as the variable a1 is ambigous

    // to resolve this we use the concept of virtual class
    // both classes B nad C sholud be virtual in the scenario

    cout<<obj.a1<<endl;
    cout<<obj.a2<<endl;


}
#include<iostream>
using namespace std;

class A {
    public:
    void x(){
        cout<<"x member"<<endl;
    }

    virtual void x1()=0;
};

class B:public A{
    public:
    void x1(){
        cout<<"hi"<<endl;
    }
};

int main(){
    B obj2;
    obj2.x1();
    obj2.x();
}
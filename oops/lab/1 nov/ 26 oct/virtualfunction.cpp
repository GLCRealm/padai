#include<iostream>
using namespace std;

class A{
    public:
    void x(){
        cout<<"you are in function 1"<<endl;
    }
    void x(int a){
        cout<<"you are in function 2"<<endl;
    }
    void x(int c,int b){
        cout<< "you are in function 3"<<endl;
    }
    void virtual y(){
        cout<<"you are in class A"<<endl;
    }
};

class B: public A{
    public:
    void virtual y(){
        cout<<"you are in class B"<<endl;
    }
};

int main(){
    A obj;
    B obj2;

    obj.x();
    obj.x(1);
    obj.x(1,2);
    obj2.y();
    A*ptr = new B();
    ptr->y();
}
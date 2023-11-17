#include <iostream>
using namespace std;

class A{
    public:
    int a=1;

    void a2(){
        cout<<"you are in function a2"<<endl;
    }
};

class B{
    public:
    int a=2;
    void b2(){
        cout<<"you are in function b2"<<endl;
    }
};

class C:public A,public B{
    public:
    int c=3;

    void c2(){
        cout<<"you are in function c2"<<endl;
    }
};

int main(){
    C obj;
    
    //cout<<obj.a<<endl; // this will show the ambiuous error

    cout<<obj.B::a<<endl; // the problem is resolved by using scope resolution operator ::
    cout<<obj.A::a<<endl;
    
    obj.a2();
    obj.b2();
    obj.c2();
}
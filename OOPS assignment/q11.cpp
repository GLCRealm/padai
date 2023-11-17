#include<iostream>
using namespace std;

class A{
    public:
    int a=10;
};

class B{
    public:
    int a=20;
};

class C : public A,public B{};

int main(){
    C obj;
    cout<<obj.A::a<<endl;
    cout<<obj.B::a<<endl;
}
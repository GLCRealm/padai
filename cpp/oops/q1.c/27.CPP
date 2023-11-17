#include<iostream>
using namespace std;

class A{
    public:
    int a1 = 1;
    int a2 = 2;
};

class B:public A
{
    int b =3;
};

class C:public A{
    int c=4;
};

class D : public A,public B
{
    int d=5;
};

int main(){
    D obj;

    cout<<obj.a1;
}

#include <iostream>
using namespace std;

class A{
    public:
    int a=10;

    A(){
        cout<<"you are in class A default constructor.."<<endl;
    }

    A(int x){
        cout<<"you are in class A paramerised constructor.."<<endl;
        cout<<x*2<<endl;
    }
};

class B{
    public:
    int b=20;

    B(){
        cout<<"you are in class B default constructor.."<<endl;
    }

    B(int x){
        cout<<"you are in class B paramerised constructor.."<<endl;
        cout<<x*3<<endl;
    }
};

class C:public A, public B{ //the order of class A,B will effect the output
    public:

    C(){
        cout<<"you are in class C default constructor.."<<endl;
    }

    C(int x):A(10),B(10){  //the order of calling constructer dont efftect the order of o/p
        cout<<"you are in class C parameterised constructor.."<<endl;
        cout<<x*4<<endl;
    }
};

int main(){
    cout<<"\nThis is about the super class and how to inherite parameierised constructer\n"<<endl;

    C();
    C(12);
    
}

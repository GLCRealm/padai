#include<iostream>
using namespace std;

class A{
    public:
    int a=10;

    void x(){
        cout<<"you are in function with no parameter "<<endl;
    }

    void x(int a){
        cout<<"you are in function with 1 parameter "<<endl;
    }

    void x(int a, int b){
        cout<<"you are in function with 2 parameter "<<endl;
    }

    A(){
        cout<<"This is an example of function overloading"<<endl;
    }
};

class B{
    public:
    void x(){
        cout<<"you are in class B"<<endl;
    }
};

class C{
    public:
    void x(){
        cout<<"you are in class C"<<endl;
    }
    C(){
        cout<<"\nThis is example od function overriding"<<endl;
    }

    void y();
};

int main(){
    A obj;
    obj.x();
    obj.x(1);
    obj.x(1,2);

    C o;
    B a;
    a.x(); //here the function is cominig from class B
    o.x(); // here the same function is coming fron class C with updated value
}

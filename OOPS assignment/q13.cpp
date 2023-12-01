#include<iostream>
using namespace std;

class A{
    public:
    A(){
        cout<<"you are in parent class"<<endl;
    }
    ~A(){
        cout<<"DESTRUCTOR OF PARENT CLASS IS CALLED"<<endl;
    }
};

class B:public A{
    public:
    B(){
        cout<<"you are in child class"<<endl;
    }
    ~B(){
        cout<<"DESTRUCTOT OF CHILD CLASSIS CALLED"<<endl;
    }
};

int main(){
    B obj;
}
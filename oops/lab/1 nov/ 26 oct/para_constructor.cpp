#include <iostream>
using namespace std;

class A{
    public:
    int a=10;

//this is default constructor

    A(){
        cout<<"you are in default consructor..."<<endl;
        cout<<a<<endl;
    }

//this is a parameterised constructor with 1 parameter

    A(int x){
        cout<<"you are in parameterised constructor"<<endl;
        cout<<x*a<<endl;
    }

//this is also parameterised constructor with 2 parameters

    A(int x,int y){
        cout<<"you are in parameterised constructor"<<endl;
        cout<<y*x*a<<endl;
    }
};

int main(){
    cout<<"THIS IS TO DEMOSTRATE THE USE OF CONSTRUCTORS\n"<<endl;

    A();
    A(2);
    A(2,3);
}
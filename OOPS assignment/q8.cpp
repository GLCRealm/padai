#include<iostream>
using namespace std;

class A{
    public:
    int a;
    int *ptr=new int;

    A(int a){
        cout<<endl<<a<<endl;
    }

};

int main(){

    A obj;
    obj.A(2);
    
}
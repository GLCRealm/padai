#include<iostream>
using namespace std;

class A{
    public:
    int a;
    int  *ptr;

    void data(int x, int y){
        a=x;
        ptr=new int;
        *ptr= y;
    }

    void print(){
        cout<<a<<endl;
        cout<<*ptr<<endl;
    }

    A(){
        a=d.a;
        p=d.p;
    }

};

int main(){
    A obj;

    obj.data(10,20);
    obj.print();

    A obj2;
    obj2.print();

    
}
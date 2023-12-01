#include<iostream>
using namespace std;;

class A{
    public:
    int a1=10;

    private:
    int a2=20;

    protected:

    int a3=30;

};

class B:public A{
    public:
    int b1= 40; 

    void x(){
        cout<<a2<<endl;; //cant access this as this is private 
        cout<<a1<<endl;
        cout<<a3<<endl;//able to access the protected variable from function
    }

    private:
    int b2= 50;

    protected:
    int b3= 60;


};

int main(){
    B obj;

    //cout<<obj.a3<<endl;  // cannot access the protected and private variable form main function
    //cout<<ojb.a2<<endl;

    obj.x();// able to access the prostected variable from function
}
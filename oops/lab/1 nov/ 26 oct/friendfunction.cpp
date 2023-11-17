#include<iostream>
using namespace std;

class A{
    
    private:
    int a=10;

    public:
    int b=20;

    friend void nigga();
    friend void nigga2(int x);
};

void nigga(){
    A obj;
    cout<<"you are inside friend function congrats"<<endl;
    cout<<obj.a<<endl;
}

//this is paraterised friend function
void nigga2(int x){
    A obj;
    cout<<"you are inside 2ed friend function congrats"<<endl;
    cout<<(obj.a)*x<<endl;
}

int main(){

    A obj;

    cout<<"\nTHIS IS FOR THE WORKING OF FRIEND FUNCTION\n"<<endl;

    nigga();
    cout<<obj.b<<endl;
    nigga2(2);
}

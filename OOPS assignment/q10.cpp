#include<iostream>
using namespace std;

class A{
    private:
    int a=20;
    public:
    friend void x();
};

void x(){
    A obj;
    cout<<obj.a<<endl;
}

int main(){
    x();
}
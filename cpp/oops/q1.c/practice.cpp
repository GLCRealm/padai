#include<iostream>
using namespace std;

class area{

    public:
    int data;
    int a;
};

int main(){

    area hello;
    hello.data=10;
    hello.a=1;

    area hi=hello;

    std::cout<<hi.data<<endl; 
    std::cout<<hi.a<<endl;
} 
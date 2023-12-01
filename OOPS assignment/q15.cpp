#include<iostream>
using namespace std;

int add(int a, int b){
    return a+b;
}

double add(double a,double b){
    return a+b;
}

int main(){
    cout<<"The total is "<<add(5,7)<<endl;
    cout<<"The total is "<<add(6.3,3.9)<<endl;
}
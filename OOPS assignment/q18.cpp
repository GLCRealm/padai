#include<iostream>
using namespace std;

class vehicle{
    public:
    void virtual wheels(){
        cout<<"vehicle have wheels"<<endl;
    } 
};

class car:public vehicle{
    public:
    void wheels(){
        cout<<"car have 4 wheels"<<endl;
    }
};

int main(){
    vehicle *ptr= new car();
    ptr->wheels();
}
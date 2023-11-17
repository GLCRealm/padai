#include<iostream>
#include<string>
using namespace std;

class employee{
    public:
    string name;
    int *age;

    employee(){
        name="kajal";
        *age=18;

        cout<<"NAME:-"<<name<<endl<<"AGE:-"<<*age<<endl;    
    }

    ~employee(){
        cout<<"The destructor has been called and the memory is now free"<<endl;
    }
};

int main(){
    employee obj;
}
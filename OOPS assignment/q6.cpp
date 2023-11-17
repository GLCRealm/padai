#include<iostream>
#include<string.h>
using namespace std;

class student{
    public:
    string name;
    int age;

    student(){
        name="akash";
        age=19;
        cout<<"NAME- "<<name<<", AGE- "<<age<<endl;
    }

    student(int age,string name){
        cout<<"NAME- "<<name<<", AGE- "<<age<<endl;
    }
};

int main(){
    student obj1;
    student obj2(20,"anshdeep");
}

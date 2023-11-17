#include <iostream>
using namespace std;

class A{
    public:
    void x(){
        cout<<"inside 1st function"<<endl;
    }
    void x(int a){
        cout<<"inside the 2ed function"<<endl;
    }
};

class B:public A{
    public:
    void x(){
        A::x(); //we can write it lke this 
        cout<<"inside B class"<<endl;
    }
    
};

int main(){
    B obj;
    obj.x();
    //obj.x(2);

    //obj.A::x();// and like this
}


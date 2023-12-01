#include<iostream>
using namespace std;

class A{
    public:
    int a=10;
};

//single inheritence
class B:public A{
    public:
    int b=20;
};

//multilevel inheritence
class C:public B{
    public:
    int c=30;
};

//multipal inheritance
class D{
    public:
    int d=40;
};

class E:public A,public D{
    public:
    int e=50;
};

//heirarchial inheritance
class F:virtual public A{
    public:
    int f=60;
};
class G:virtual public A{
    public:
    int g=70;
};

//hybrid inheritance
class H:public F,public G{
    public:
    int h=80;
};

int main(){
    //single inheritance
    B objB;
    cout<<endl<<"single inheritance "<<endl<<objB.a<<endl;
    cout<<"10 is from class A"<<endl<<endl;

    //multilevel inheritance
    C objC;
    cout<<"multilevel inheritance "<<endl<<objC.a<<endl<<objC.b<<endl;
    cout<<"10,20 are from class A and B"<<endl<<endl;

    //multiple inheritance
    E objE;
    cout<<"multiple inheritance"<<endl<<objE.a<<endl<<objE.d<<endl;
    cout<<"10 and 40 is from class A and D"<<endl<<endl;

    //hierarchical inheritance
    F objF;
    G objG;
    cout<<"hierarchical inheritance"<<endl<<objF.a<<endl<<objG.a<<endl;
    cout<<"10 is from A class printed by object of F and G class"<<endl<<endl;

    //hybrid inheritance
    H objH;
    cout<<"hybrid inheritance"<<objH.a<<endl<<objH.f<<endl<<objH.g<<endl;
    cout<<"10 is from A class which is inherited by F and G class which is further inherited by H class"<<endl<<endl;
    
}
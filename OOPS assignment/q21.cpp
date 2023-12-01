#include<iostream>
#include<stdexcept>
using namespace std;

int main(){
    cout<<"Enter the number"<<endl;
    int num;
    cin>>num;

    try{
        if(num==0){
            throw runtime_error("Cannot divide by 0");
        }
        else{
            cout<<100/num<<endl;
        }
    }
    catch(runtime_error x){
        cout<<"Error caught..."<<x.what()<<endl;
    }
    cout<<"Bye"<<endl;
}

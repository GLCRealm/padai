#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream i;
    fstream j("newfile.txt");

    i.open("/workspaces/padai/OOPS assignment/hello.txt");
    string line,line2;

    while(getline(i,line)){
        j<<line<<endl;
    }
    
    j.seekg(0);

    while(getline(j,line2)){
        cout<<line2<<endl;
    }
}
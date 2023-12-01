
#define  opera;

namespace n1{
    int add(int a,int b){
        return a+b;
    };
    int subtract(int a, int b){
        return a-b;
    };
}

namespace n1{
    int multiplay(int a, int b){
        return a*b;
    };
    int divide(int a, int b){
        if(b!=0){
            return a/b;
        }
        return 0;
        
    };
}
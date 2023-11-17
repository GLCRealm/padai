#include<stdio.h>

int main(){
    int a;
    int i=0;
    printf("enter a number\n");
    scanf("%d",&a);

    while(i*2!=a){
        i++;
    }

    if(2*i==a){
    printf("its even\n");
    }

    else{
        printf("its odd\n");
    }


    //printf("its odd\n");
    
   
}


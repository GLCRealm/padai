#include <stdio.h>

int main(){

int arr[10]={2,5,1,7,6,3,9,4,8,10};
int n=10;

    for(int i = 0; i<n; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }    

    for(int i= 0; i<n;i++){   
        printf("%d\t",arr[i]);
    }
}




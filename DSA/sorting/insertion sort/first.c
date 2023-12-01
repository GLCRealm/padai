#include<stdio.h>

int main(){
    int arr[10]={7,5,9,6,3,4,8,1,10,2};
    int n = 10;

    for(int i =1; i<n;i++){
        int temp=arr[i];
        int j;
        for( j =i-1;j>=0&&arr[j]>temp;j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }

    for(int i = 0; i<n;i++){
        printf("%d\t",arr[i]);
    }
}
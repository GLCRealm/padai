#include<stdio.h>
#include<stdlib.h>

//bubble sort
void bubblesort(int a[],int n){
    int c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                c=a[j];
                a[j]=a[j+1];
                a[j+1]=c;
            }
        }
    }

    printf("the sorted array is :-\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
    int b;
    printf("enter the no of element in array:-\n");
    scanf("%d",&b);
    int a[b];
    for(int i=0;i<b;i++){
        printf("enter the elemet %d:-\n",i+1);
        scanf("%d",&a[i]);
    }

    bubblesort(a,b);

}
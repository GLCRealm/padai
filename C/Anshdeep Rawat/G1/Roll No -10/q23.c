#include<stdio.h>
#include<stdlib.h>

//insertation sort
void insertion(int a[], int n) {
    int min, j;
    for(int i=1;i<n;i++) {
        min=a[i];
        j=i-1;
        while(j>=0&&a[j]>min) {
            a[j+1]=a[j];
            j=j-1;
        }

        a[j+1]=min;
    }

    printf("the sorted array is :-\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
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
    insertion(a,b);
}
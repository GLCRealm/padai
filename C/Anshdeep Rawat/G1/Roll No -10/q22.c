#include<stdio.h>
#include<stdlib.h>

//sellection sort
void selection(int a[], int n){
    int c;
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        c = a[i];
        a[i] = a[min];
        a[min] = c;
    }
    
    printf("the sorted array is :-\n");
    for(int i = 0; i < n; i++){
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
    selection(a,b);
}
#include<stdio.h>
#include<stdlib.h>

//quick sort
int partition(int a[], int low, int val) {
    int p = a[val]; 
    int i = (low - 1); 

    for (int j = low; j <= val - 1; j++) {
         
        if (a[j] <= p) {
            i++; 
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
 
    int temp = a[i + 1];
    a[i + 1] = a[val];
    a[val] = temp;

    return i + 1;
}

void quickSort(int a[], int low, int val) {
    if (low < val) {
        int pi = partition(a, low, val);

        
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, val);
    }
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

    printf("the sorted array is :-\n");
    quickSort(a,0,b-1);
    for(int i = 0; i < b; i++){
        printf("%d ", a[i]);
    }
}
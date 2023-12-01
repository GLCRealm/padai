#include<stdio.h>
#include<stdlib.h>

//merge sort
void merge(int a[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (j = 0; j < n2; j++)
        R[j] = a[middle + 1 + j];

  
    i = 0; 
    j = 0; 
    k = left; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergesort(a, left, middle);
        mergesort(a, middle + 1, right);

        // Merge the sorted halves
        merge(a, left, middle, right);
        
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

    mergesort(a,0,b-1);
    
    printf("the sorted array is :-\n");
    for(int i = 0; i < b; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

}
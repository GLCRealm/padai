// #include<stdio.h>
// #include<stdlib.h>

// //quick sort
// int partition(int a[], int low, int val) {
//     int p = a[val]; 
//     int i = (low - 1); 

//     for (int j = low; j <= val - 1; j++) {
         
//         if (a[j] <= p) {
//             i++; 
//             int temp = a[i];
//             a[i] = a[j];
//             a[j] = temp;
//         }
//     }
 
//     int temp = a[i + 1];
//     a[i + 1] = a[val];
//     a[val] = temp;

//     return i + 1;
// }

// void quickSort(int a[], int low, int val) {
//     if (low < val) {
//         int pi = partition(a, low, val);

        
//         quickSort(a, low, pi - 1);
//         quickSort(a, pi + 1, val);
//     }
// }

// int main(){
//     int b;
//     printf("enter the no of element in array:-\n");
//     scanf("%d",&b);
//     int a[b];
//     for(int i=0;i<b;i++){
//         printf("enter the elemet %d:-\n",i+1);
//         scanf("%d",&a[i]);
//     }

//     printf("the sorted array is :-\n");
//     quickSort(a,0,b-1);
//     for(int i = 0; i < b; i++){
//         printf("%d ", a[i]);
//     }
// }

#include <stdio.h>
#include <stdlib.h>

// Quick sort for characters
int partition(char a[], int low, int high) {
    char pivot = a[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (a[j] <= pivot) {
            i++;
            char temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    char temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(char a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the number of characters in the array: ");
    scanf("%d", &n);

    // Clear the newline character from the buffer
    while (getchar() != '\n');

    char characters[n];

    printf("Enter the sequence of characters: ");
    for (int i = 0; i < n; i++) {
        scanf("%c", &characters[i]);
    }

    // Sorting the array of characters
    quickSort(characters, 0, n - 1);

    printf("\nSorted characters: ");
    for (int i = 0; i < n; i++) {
        printf("%c ", characters[i]);
    }

    return 0;
}

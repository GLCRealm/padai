#include <stdio.h>
#include <string.h>

void change(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int divide(char arr[], int min, int max) {
    int a = arr[max];
    int i = min - 1;

    for (int j = min; j <= max - 1; j++) {
        if (arr[j] < a) {
            i++;
            change(&arr[i], &arr[j]);
        }
    }
    change(&arr[i + 1], &arr[max]);
    return i + 1;
}

void quicksort(char arr[], int min, int max) {
    if (min < max) {
        int pi = divide(arr, min, max);

        quicksort(arr, min, pi - 1);
        quicksort(arr, pi + 1, max);
    }
}

void printarr(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n=100;

    char arr[n];
    printf("Enter string you want to sort:\n");
    fgets(arr,sizeof(arr), stdin);

    int size = strlen(arr);

    if (size>0&&arr[size-1]=='\n') {
        arr[size -1] = '\0';
        size--;
    }

    printf("Original string is:- ");
    printarr(arr, size);

    quicksort(arr, 0, size - 1);

    printf("The sorted string is : ");
    printarr(arr, size);

    return 0;
}
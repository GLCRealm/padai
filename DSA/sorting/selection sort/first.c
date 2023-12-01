#include <stdio.h>

// void selectionsort(int ){

//     for(int i=0; i<n-1; i++){
//         int min=i;
//         for(int j=i+1; j<n; j++ ){
//             if (arr[j]<arr[min]){
//                 min=j;   
//             }    
//         }
//         int temp=arr[i];
//         arr[i]=arr[min];
//         arr[min]=temp;
//     }
//     for(int i=0; i<n;i++){
//         printf("%d\t",arr[i]);
//     }

// }

int main(){
    
    int n=10;
    int arr[10]={2,4,7,3,8,1,9,6,10,5};
    // int *ptr=arr[10];

    // printf("%d",*ptr);

    for(int i=0; i<n-1; i++){
        int min=i;
        for(int j=i+1; j<n; j++ ){
            if (arr[j]<arr[min]){
                min=j;   
            }    
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    for(int i=0; i<n;i++){
        printf("%d\t",arr[i]);
    }

    // selectionsort(arr[]);

}

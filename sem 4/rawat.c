#include<stdio.h>

int lin(){
int b,c;
    printf("enter the number of element in array\n");
    scanf("%d",&b);
    int a[b];
    for (int i=1;i<=b;i++){
        printf("enter the numbers in array\n");
        scanf("%d",&a[i]);
    }
    printf("enter the element you want to search\n");
    scanf("%d",&c);
    for(int i =0;i<=b;i++){
        if(c==a[i]){
            printf("element found %d\n",a[i]);
            return 0;
        }
    }
    printf("element not found\n" );
}

int main(){
lin();
}

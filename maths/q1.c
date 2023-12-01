#include <stdio.h>
#include <stdlib.h>

void function(int val[],int a){
    printf("\n\nthe function is 1/x\n\n");
    printf("the elements of function is :-\n");
    for(int i =0;i<a;i++){
        printf("1/%d\n",val[i]);
    }
    printf("the inverse of the element is:-\n");
    for(int i=0;i<a;i++){
        printf("%d\n",val[i]);
    }
}
int main() {
    int a;
    printf("enter the number of elements you want to insert:-\n");
    scanf("%d",&a);	
    int b[a];
	
    for(int i=0;i<a;i++){
        printf("enter the element %d:-\n",i);
        scanf("%d",&b[i]);
    }  

    function(b,a);
}
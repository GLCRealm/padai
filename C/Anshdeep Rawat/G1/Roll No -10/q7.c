#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,*p,a=0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    if(p==NULL)                     
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
    printf("Enter elements of array: ");
    for(i=0;i<n;++i)
    {
        scanf("%d",p+i);
        a+=*(p+i);
    }
    printf("a=%d",a);
    free(p);
}

#include <stdio.h>
 
int main()
{
    int i, num, b = 0,a[100] ;
 
    printf("Enter the number of elements\n");
    scanf("%d", &num);
    for (i = 0; i <num; i++)
    scanf("%d",&a[i]);

    for (i = 0; i < num; i++)
    {
        if (a[i] % 2!= 0)
            b = b + a[i];
        
    }
    printf("Sum of all odd numbers = %d\n", b);
    return 0;
}
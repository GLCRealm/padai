#include <stdio.h>

void revers(int n){
    int sum;
    int a = n;
    int reverse = 0;

    while (n != 0)
    {
        int add = n % 10;
        reverse = reverse * 10 + add;
        n = n / 10;
    }
    sum = a + reverse;
    printf("The reverse sum is : %d", sum);
}

int main()
{
    int a;
    printf("enter the value:-\n");
    scanf("%d",&a);
    revers(a);
}
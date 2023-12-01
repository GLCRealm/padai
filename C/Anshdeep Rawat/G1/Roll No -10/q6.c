#include<stdio.h>
int main() {
   int a[30], i, b, c;
 
   printf("\nEnter the no of elements :");
   scanf("%d", &b);
 
   for (i = 0; i < b; i++)
      scanf("%d", &a[i]);
 
   c = a[0];
 
   for (i = 0; i < b; i++) {
      if (a[i] > c) {
         c = a[i];
      }
   }
 

   printf("\nThe largest element : %d", c);

}
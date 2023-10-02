#include<stdio.h>
 
int print(int a[], int b[], int c, int d)
{
  int i = 0, j = 0;
  while (i < c && j < d)
  {
    if (a[i] < b[j])
      printf(" %d ", a[i++]);
    else if (b[j] < a[i])
      printf(" %d ", b[j++]);
    else
    {
      printf(" %d ", b[j++]);
      i++;
    }
  }
 
 
  while(i < c)
   printf(" %d ", a[i++]);
  while(j < d)
   printf(" %d ", b[j++]);
}
 

int main()
{
  int a[] = {1, 2, 4, 5, 6};
  int b[] = {2, 3, 5, 7};
  int c = sizeof(a)/sizeof(a[0]);
  int d = sizeof(b)/sizeof(b[0]);
  print(a, b, c, d);
  getchar();
  return 0;
 }


#include <stdio.h>

void reverse(int arr[], int start, int end)
{
  int temp;
  while(start < end)
  {
    temp = arr[start];   
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }   
}     
 
void arry(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);
 
  printf("\n");
} 
 

int main() 
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  arry(arr, 8);
  reverse(arr, 0, 7);
  printf("The reversed array is \n");
  arry(arr, 8);
  getchar();
  return 0;
}

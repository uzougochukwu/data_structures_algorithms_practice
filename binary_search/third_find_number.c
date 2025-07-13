// binary search in C
#include <stdio.h>

int binarySearch(int array[], int x, int low, int high){

  while (low <= high){

    int mid = low + (high - low) / 2;

    if(x == array[mid])
      return mid;

    if(x > array[mid])
      low = mid + 1;
    else
      high = mid - 1;

    
  }

  return -1;

}

int main(void){

  int array[] = {2,3,4,5,6};
  int x = 3;
  int n = sizeof(array) / sizeof(array[0]);

  int result = binarySearch(array, 3, 0, n - 1);

  if (result == -1)
    printf("Not found");
  else
    printf("Element found at index %d", result);
  return 0;

}

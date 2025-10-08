// binary search in C
#include <stdio.h>

int binarySearch(int array[], int x, int low, int high){

  while (low <= high){ // must be less than or equal. if x is the largest value in the array, then eventually the low value will keep increasing until it is in line with the high. this is because the high stays at the end.

    int mid = low + ((high - low) / 2);

    if(x == array[mid])
      return mid;

    if(x > array[mid]) // must be greater than. if x is equal to the array[mid] then we don't want to change the low value, we want to return mid. but in this case it doesn't really matter, since the x == array[mid] above will catch it if mid is the correct position
      low = mid + 1;
    else
      high = mid - 1;

    
  }

  return -1;

}

int main(void){

  int array[] = {2,3,4,5,6};
  int x = 2;
  int n = sizeof(array) / sizeof(array[0]);

  int result = binarySearch(array, x, 0, n - 1);

  if (result == -1)
    printf("Not found");
  else
    printf("Element found at index %d", result);
  return 0;

}

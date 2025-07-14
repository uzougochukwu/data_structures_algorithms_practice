#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// comparison function for qsort
int compare(const void *a, const void *b){
  return(*(int *)a - *(int *)b);
}

// function to check whether any pair exists
// whose sum is equal to the given target value

bool twoSum(int arr[], int n, int target){

  // sort the array
  qsort(arr, n, sizeof(int), compare);

  int left = 0, right = n - 1;

  // iterate while left pointer is less than right pointer

  while (left < right){
    int sum = arr[left] + arr[right];

    // check if the sum matches the target
    if (sum == target)
      return true;
    else if (sum < target)
      left++; // move left pointer to the right
    else
      right--; // move right pointer to the left
  }

  // if no pair is found
  return false;

}

int main(){
  int arr[] = {0, -1, 2, -3, 1};
  int target = -2;

  int n = sizeof(arr) / sizeof(arr[0]);


  // call the twoSum function and print the result
  if (twoSum(arr, n, target))
    printf("true\n");
  else
    printf("false\n");

  return 0;


}


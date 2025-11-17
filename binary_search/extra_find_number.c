#include <stdio.h>
#include <stdlib.h>


int binary_search(int array[], int x, int low, int high){


  while (low <= high){

    int mid = low + ((high-low)/2);

    if (array[mid] == x){
      return mid;
    }

    if (x > array[mid]){
      low = mid + 1;

    }else{
      high = mid - 1;

    }



  }

  return -1;



}

int main(){


  int a[] = {1, 3, 5, 6,7, 9};

  int length = 6;

  int x = 1;

  int index = binary_search(a, 1, 0, length -1);

  printf("element found at index %d", index);

  return 0;


}

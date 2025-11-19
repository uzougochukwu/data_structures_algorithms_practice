// from this video https://www.youtube.com/watch?v=0jDiBM68NGU

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y);
void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int high);
int partition(int array[], int low, int high);

int main()
{

  int a[] = {10, 11, 23, 44, 8, 15, 3, 9, 12, 45, 56, 45, 45};

  int length = 13;

  quicksort(a, length);

  for (int i = 0; i < length; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
    
  return 0;
}


void swap(int *x, int *y){
  
  int temp = *x;

  *x = *y;

  *y = temp;
}


void quicksort(int array[], int length){

  srand(time(NULL));

  quicksort_recursion(array, 0, length -1);

}

void quicksort_recursion(int array[], int low, int high){

  if (low < high){

  int pivot_index = partition(array, low, high);

  quicksort_recursion(array, low, pivot_index - 1);

  quicksort_recursion(array, pivot_index + 1, high);

  }  
}


int partition(int array[], int low, int high){

  int pivot_index = low + (rand() % (high - low));

  if (pivot_index != high)
    swap(&array[pivot_index], &array[high]);
  
  int pivot_value = array[high];

  int i = low;

  for (int j = low; j < high; j++)
    {
      if (array[j] <= pivot_value){
	swap(&array[i], &array[j]);
	i++;  // must increment i, otherwise we are moving the j values to the same position every time we swap
      }
    }

  swap(&array[i], &array[high]); // this puts the pivot (which is array[high] into the position it will occupy when the sort is finished.
  // remember, i is only incremented when we find an element that is less than or equal to the pivot value
  // which means that when we finally exit the for loop, i is at the position of the first element to be greater than the pivot, so it makes sense to swap the element at i with the pivot value (array[high]), so that the pivot value serves its role as a pivot
  // everything to the left of the pivot will be less than, everything to the right will be greater than

  return i;
}

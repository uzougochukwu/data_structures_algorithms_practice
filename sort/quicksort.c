#include <stdio.h>

int swap(int pos_A, int pos_B, int array[], int array_length){

    //if position of A or B is out of bounds of array
  if (pos_A > array_length - 1 )
  return -1;

  if (pos_B > array_length -1 )
    return -1;

  // must save the value at position A to a temporary variable

  int tmp_value = array[pos_A];
  
  array[pos_A] = array[pos_B]; // set the value at position A to be the value at position B

  printf("the value at position A of %d has been set to the value at position B, which is %d\n", tmp_value, array[pos_B]);

  array[pos_B] = tmp_value; // set the value at position B to be the temporary variable (which is what the value at A was, before the swap)

  printf("the value at position B of %d has been set to the original value at position A, which is %d\n", array[pos_A], tmp_value);
  
  return 0;


}


int main(){

  int array[5] = {1,2,3,4,5};

  int array_length = sizeof(array)/sizeof(array[0]);

  printf("This element is %d\n", array[3]);

  int new_array[5] = {};

  array[0] = 4;

  printf("the element at index 0 of the array is %d\n", array[0]);

  array[0] = 5;

   printf("the element at index 0 of the array is now %d\n", array[0]);

   printf("the array is of length %d\n", array_length);
   

  return 0;

}

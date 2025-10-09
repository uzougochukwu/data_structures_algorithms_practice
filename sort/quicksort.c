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

int print_entire_array(int array[], int array_length){

  for (int i = 0; i < array_length; i++) {
    printf("%d,", array[i]);

  }

  printf("\n");

  return 0;
}

int main(){

  int array[5] = {1,2,3,4,5};

  int array_length = sizeof(array)/sizeof(array[0]);

  print_entire_array(array, array_length);

  swap(0, 4, array, array_length);


  // need a data structure to contain a list of sub arrays, when the sub arrays are all of length 1, we know that the sort is finished
  // for each sub array, record the starting index and the length of the sub array

  
  
    
      
  return 0;

}

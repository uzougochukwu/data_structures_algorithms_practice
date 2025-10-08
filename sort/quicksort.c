#include <stdio.h>



int main(){

  int array[5] = {1,2,3,4,5};

  printf("This element is %d\n", array[3]);

  int new_array[5] = {};

  array[0] = 4;

  printf("the element at index 0 of the array is %d\n", array[0]);

  array[0] = 5;

   printf("the element at index 0 of the array is now %d\n", array[0]);

  return 0;

}

#include <stdio.h>

int main() {

char array[5][3] = {"S\0", "A\0", "B\0", "C\0", "D\0"};
 
//puts(array[3]);

int length = sizeof(array)/sizeof(array[0]);

char stack[5] = {};

//printf("%d", length);

//stack[0] = *array[0]; // *array[0] is the memory address

for (int i = 0; i < length; i++){
  stack[i] = *array[i];
  printf("%s", &stack[i]);
  //printf("%d", i);
  
 }
 
// printf("%s", &stack[0]); // the &stack[0] is now dereferencing that pointer
 
return 0;

}




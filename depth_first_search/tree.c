#include <stdio.h>

int main() {

char array[5][3] = {"S\0", "A\0", "B\0", "C\0", "D\0"};

int length = sizeof(array)/sizeof(array[0]);

char stack[5] = {};

for (int i = 0; i < length; i++){
  stack[i] = *array[i];
  printf("%s", &array[i]);

  
 }

return 0;

}




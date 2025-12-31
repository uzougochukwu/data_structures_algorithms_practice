#include <stdlib.h>
#include <stdio.h>

int main(){

  int a=5;

  int *ptr = &a;

  // printf("%u is ptr\n", ptr);
  
  ptr = (int *)((char *)ptr + 100);

  //  printf("%u is ptr\n", ptr);


  // ptr = ptr + 100;
  
  return 0;
}

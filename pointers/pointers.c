#include <stdio.h>


/*
  
pointers are a special type of variable, you declare one by putting an * before it
int *p = NULL; In this case, the * means that p is a pointer.

The address of a variable is created by putting the & before it, so &age is the address of age, which can then be stored in a pointer type variable

To dereference a pointer, you can put an asterisk before the pointer, to access the value, so *p. In this case the * means indirection.

 */

int main(){

  int y = 7;
int *p = &y; // this means that p stores the memory addres of y

  *p = 14;
printf("%p, %i\n", p, *p);

}

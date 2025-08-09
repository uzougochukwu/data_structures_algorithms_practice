#include <stdlib.h>
#include <stdio.h>

struct node {
  int value;
  struct node* next;
};

typedef struct node node_t;

int main() {

  node_t p;

  node_t *result_p;

  p.value = 5;

  result_p = malloc(sizeof(node_t));

  p.next = result_p;

  node_t o;

  node_t *result_o;

  o.value = 8;

  //o.next = malloc(sizeof(node_t));

  node_t *i = malloc(sizeof(node_t));

  o.next = i;

  i->value = 10;

  // use malloc to return a pointer and set that to o.next
  // create new node_t struct with the address being the address stored in o.next
  

   printf("The next pointer of o is %d and the address of i is %d\n", o.next, i);

  /*
  printf("The first value %d is located at memory address %d\n", p.value, p.next);

  printf("The second value %d is located at memory address %d\n", o.value, o.next);
  */
  return 0;
}

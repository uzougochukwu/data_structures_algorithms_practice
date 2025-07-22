#include <stdlib.h>
#include <stdio.h>

struct node {
  int value;
  struct node* next;
 };

typedef struct node node_t;

void printList(node_t *head){
  node_t *temporary = head;

  while(temporary != NULL) {
    printf("%d - ", temporary->value);
    temporary = temporary -> next;
  }

  printf("\n");

}

int main() {
  node_t n1, n2, n3;
  node_t *head;

  n1.value = 45;
  n2.value = 8;
  n3.value = 32;

  // link them up
  head = &n1;
  n3.next = NULL;
  n2.next = &n3;
  n1.next = &n2; // so we know when to stop

  node_t n4;
  n4.value = 13;
  n4.next = &n3;
  n2.next = &n4;

  head = head->next;

  printList(head);
  
  return 0;
}

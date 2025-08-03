#include <stdio.h>
#include <stdlib.h>

struct node{
  int value;
  struct node* next;
};

typedef struct node node_t;

node_t a;

node_t *create_new_node( int value ){
  node_t (*result) = malloc(sizeof(node_t)); // allocate enough memory for a new node_t struct, malloc returns a pointer so set that pointer to be *result 
  result->value = value; // the value part of that new node is equal to the value that was passed to this function as a parameter
  result->next = NULL; // the next part of that new node points to NULL as it needs to be hooked up
  return result;  // return the new node
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert) {
  node_to_insert->next = *head; // the next portion of the node_to_insert is a pointer, pointing to the head pointer
  *head = node_to_insert; // the address stored in the head pointer is changed
  return node_to_insert;
}

int main() {

node_t *head = NULL;
node_t *tmp;

for (int i = 0; i < 5; i++) {
  tmp = create_new_node(i);
  head = insert_at_head(&head, tmp);
}

a.value = 5;
printf("%d", a.value);

return 0;
  
}

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

node_t *find_node(node_t *head, int value){

  node_t *tmp = head; // set the temporary node to be equal to the current head

  while (tmp != NULL) {
    if (tmp->value == value) return tmp;
    tmp = tmp->next;
  }

  return NULL;
}

void insert_after_node(node_t *node_to_insert_after, node_t* newnode){
  newnode->next = node_to_insert_after->next;
  node_to_insert_after->next = newnode;
  
}

int main() {

node_t *head = NULL;
node_t *tmp;

for (int i = 0; i < 25; i++) {
  tmp = create_new_node(i);
  head = insert_at_head(&head, tmp);
}

 tmp = find_node(head, 13);
 printf("found node with value %d\n", tmp->value);

 insert_after_node(tmp, create_new_node(75));

a.value = 5;
printf("%d", a.value);

return 0;
  
}

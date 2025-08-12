#include <stdlib.h>
#include <stdio.h>

struct node {
  int value;
  struct node* next;
};

typedef struct node node_t;

// other functions to add:
// add node at beginning - complete
// add node at particular point - complete
// delete node at beginning
// delete node at end
// delete node at particular point

node_t* delete_node_at_beginning(node_t *first_node)
{

  // tmp node must go to the second node so it can be returned

  node_t *tmp;

  tmp->value = first_node->next->value;

  tmp->next = first_node->next->next;

  free(first_node);

  return tmp;
  /*
  node_t *tmp; // placeholder node

  tmp->value = first_node->value;

  tmp->next = first_node->next;
  
  free (first_node);

  return tmp;
  */
  
}


void print_list(node_t *current_node)
{
  while (current_node->next != NULL)
    {
  int current_value = current_node->value;
  printf(" %d ->", current_value);

  current_node = current_node->next;
    }

  printf("\n");

  return;
}

void add_node_at_end(node_t *current_node, int new_value) // will always go to the final node before adding, so long as we give it a node that currently exists
{
  while (current_node-> next != NULL)
    {
      current_node = current_node->next;
    }

  // the next pointer of the current node points to nothing, so we are at the end
  
  node_t *tmp = malloc(sizeof(node_t)); // create a new node 
  // make the next pointer of the current node point to the tmp node
  current_node->next = tmp;
  tmp->value = new_value;  
  return;
}

node_t* add_node_at_beginning(node_t *first_node, int new_value)
{

 node_t *tmp = malloc(sizeof(node_t));

 tmp->value = new_value;

 tmp->next = first_node;

 return tmp;

}

void add_node_at_particular_point(node_t *current_node, int new_value, int index) // if we pass in index as 2, that means the node we insert should occupy index 2
{
  int i = 0;

  while ( (i != index-1) && (current_node->next != NULL) ) // loop until we get to the specified index point, or until we get to the end of the linked list
    {      
      current_node = current_node->next;
      i++;
    }

  // if we are at the end, then exit the function (we already have a different function for adding nodes at the end
  if (current_node->next == NULL)
    {
      return;
    }

  // else we are at the desired node

  node_t *tmp = malloc(sizeof(node_t)); // create the new node

  // move the next pointer of the tmp node to point to the same place as the next pointer of the current node
  tmp->next = current_node->next;

  // move the next pointer of the current node to point at the new tmp node we just made
  current_node->next = tmp;

  // set the value for the tmp node we just made
  tmp->value = new_value;

  return;
}

int main() {

  node_t *head = malloc(sizeof(node_t));

  head->value = 1;

  for (int i = 2; i < 7; i++){
    add_node_at_end(head, i);
  }

  print_list(head);

  head = add_node_at_beginning(head, 20);

  print_list(head);

  add_node_at_particular_point(head, 30, 2);

  print_list(head);

  // head = head->next;
  //head->value = head->next->value;

  node_t *tmp = head; // set the value of tmp as being equal to the address of head USE THIS LINE

  printf("tmp is mem address %d and head is mem address %d\n", tmp, head);
  
  // change the address of head to be the address of the second node

  head = head->next; // USE THIS LINE

  printf("head is mem address %d and the second node is mem address %d\n", head, head->next);

  // change the value of the head to be the value of the second node

  // free the memory which tmp points to

  //delete_node_at_beginning(head); // USE THIS LINE

  free(tmp); // USE THIS LINE

  print_list(head);

  return 0;
}

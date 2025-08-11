#include <stdlib.h>
#include <stdio.h>

struct node {
  int value;
  struct node* next;
};

typedef struct node node_t;


node_t* create_new_node(node_t *node_to_add_from, int new_value)
{

  // create node using malloc
  node_t *tmp = malloc(sizeof(node_t));

  // link the node_to_add_from with the tmp node
  node_to_add_from->next = tmp;

  // set the value of the tmp node
  tmp->value = new_value;

  return tmp;
}

void print_list(node_t *current_node)
{
  while (current_node->next != NULL)
    {
  int current_value = current_node->value;
  printf(" %d -> \n", current_value);

  current_node = current_node->next;
    }

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


int main() {

  node_t *head = malloc(sizeof(node_t));

  head->value = 1;

  add_node_at_end(head, 2);

  add_node_at_end(head, 3);

  add_node_at_end(head, 4);

  // modify create_new_node to be add_node_at_end, traverse linked list till the end, then add the node, print list shows how to traverse
  /*
  node_t *tmp;

  tmp = create_new_node(head, 2);

  node_t *over;

  over = create_new_node(tmp, 3);

  node_t *again;

  again = create_new_node(over, 4);

  node_t *even;

  even = create_new_node(again, 5);
  */

  print_list(head); // print_list works somewhat

  return 0;
}

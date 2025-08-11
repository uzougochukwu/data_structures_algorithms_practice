#include <stdlib.h>
#include <stdio.h>

struct node {
  int value;
  struct node* next;
};

typedef struct node node_t;


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

  for (int i = 2; i < 7; i++){
    add_node_at_end(head, i);

  }

  print_list(head); 

  return 0;
}

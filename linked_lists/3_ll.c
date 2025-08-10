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


int main() {

  node_t *head = malloc(sizeof(node_t));

  head->value = 1;

  // modify create_new_node to be add_node_at_end, traverse linked list till the end, then add the node

  node_t *tmp;

  tmp = create_new_node(head, 2);

  node_t *over;

  over = create_new_node(tmp, 3);

  node_t *again;

  again = create_new_node(over, 4);

  node_t *even;

  even = create_new_node(again, 5);


  print_list(head); // print_list works somewhat

  return 0;
}

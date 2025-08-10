#include <stdlib.h>
#include <stdio.h>

struct node {
  int value;
  struct node* next;
};

typedef struct node node_t;

/*

create the head node

node_t *head = malloc(sizeof(node_t))

head->value = 1;
  
 */

/*

  pseudo code for function to create nodes

  take in the new_value as a parameter

  node_t *tmp = malloc(sizeof(node_t));
  tmp->value = head->value;
  tmp->next = head->next;

  while (tmp->next != null)
  {
  
  tmp->next = tmp->next->next;

  }

  tmp->value = new_value
  
 */

node_t* create_new_node(node_t *node_to_add_from, int new_value)
{

  // create node using malloc
  node_t *tmp = malloc(sizeof(node_t));

  // link the node_to_add_from with the tmp node
  node_to_add_from->next = tmp;

  // set the value of the tmp node
  tmp->value = new_value;

  // return the new node so that this can be continued
  //return tmp; // try returning node_to_add_from instead
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

  /*
  node_t *o = malloc(sizeof(node_t));

  o->value = 8;

  node_t *i = malloc(sizeof(node_t));

  o->next = i;

  i->value = 10;

  printf("The next pointer of o is %d and the address of i is %d\n", o->next, i);

  node_t *tmp = malloc(sizeof(node_t));

  tmp->value = o->value;
   
  printf("The first value is %d\n", tmp->value);
   */

  /*
  create_new_node(head, 5);

  int current = head->next->value;

  printf("Second value is %d\n", current);
   */

  node_t *head = malloc(sizeof(node_t));

  head->value = 1;

  node_t *tmp = head;

  //printf("first value is %d\n", tmp->value);

  
  
  for (int i = 2; i < 5; i++)
    {
      // use malloc to create new node outside of function, then pass it in
      node_t *tmp = head;

      head = create_new_node(tmp, i); // constantly feeding in the current head, need to feed in the result of the last function


       printf("value is %d\n", head->value);

     
    }

  // create_new_node is replacing the head value, rather than linking it up

  //printf(" final value is %d\n", head->value);

  print_list(head);

  return 0;
}

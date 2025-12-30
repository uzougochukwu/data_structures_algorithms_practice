// if you delete the head node or add a node at the beginning, then you need to use &head as the first parameter, delete_node_at_beginning(&head)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node {
  int value;
  struct node* next; // we have struct node* next because the pointer contains the address of the next struct
};

typedef struct node node_t;

//node_t *head;

void delete_node_at_end(node_t *current_node)
{

  while (current_node->next->next != NULL)
    {
      current_node = current_node->next;
    }

    // we are now at penultimate  

  node_t *tmp = current_node->next; // create a tmp node with same address as the end node

  current_node->next = NULL; // set the next pointer of penultimate node to be NULL, making it the new end node
 
  free(tmp); // free tmp, which pointed to the previous end node

  return;

}

int delete_node_at_particular_point(node_t *current_node, int index)
{
  int i = 0;

  // traverse linked list until you reach index - 1

  while ( (i != index -1) && (current_node->next != NULL) )
    {
      current_node = current_node->next;
      i++;
    }

  if (current_node->next == NULL)
    {

      return -1; // to signify that the index exceeds the length of the linked list so we must use delete_node_at_end
    }

  // create tmp node

  node_t *tmp;
  
  // have tmp equal the node at index

  tmp = current_node->next;

  // have next pointer of node at index - 1 equal to adress of node at index + 1
  current_node->next = current_node->next->next;

  // now free tmp, which has the address of the node we wish to delete

  free(tmp);

  return 0;

}



void print_list(node_t *current_node)
{
  while (current_node != NULL)
    {
  int current_value = current_node->value;
  printf(" %d ->", current_value);

  //printf(" the address is %d", &current_value);
  current_node = current_node->next;

    }

  // if it is null the while loop breaks, so we need one more final print

  // value at the very end is
  //printf(" %d ->", current_node->value);

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

  current_node = current_node->next;
  current_node->value = new_value;

  return;
}

node_t* add_node_at_beginning(node_t **head, int new_value) { // by passing in a pointer to a pointer, that means we can actually change the head pointer

 node_t *tmp = malloc(sizeof(node_t));

 tmp->value = new_value;

 tmp->next = *head; // set the next pointer of the tmp node to the same address contained in the current head pointer. this is essentially linking the tmp node to the list by adding it just before the current head node

 *head = tmp; // change the head pointer to be the address of the tmp node, so tmp is our new head node

 return tmp;


}

int add_node_at_particular_point(node_t *current_node, int new_value, int index) // if we pass in index as 2, that means the node we insert should occupy index 2
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
      return -1;
    }

  node_t *tmp = malloc(sizeof(node_t)); // create the new node

  // move the next pointer of the tmp node to point to the same place as the next pointer of the current node
  tmp->next = current_node->next;

  // move the next pointer of the current node to point at the new tmp node we just made
  current_node->next = tmp;

  // set the value for the tmp node we just made
  tmp->value = new_value;

  return 0;
}

node_t* delete_node_at_beginning(node_t **current_node) // by passing in a pointer to a pointer, that means we can actually change the head pointer
{
  // tmp pointer is equal to the head pointer (which we called current_node for convenience)
  node_t *tmp = *current_node;

  // pointer containing address of current_node is changed to contain the address of where the actual current_node's next pointer is pointing to
  // the (*current_node) is dereferencing the current_node pointer so that we can access the actual node, once we do that, we can then access the actual next pointer 
  *current_node = (*current_node)->next;

  free(tmp);

  return *current_node; // we return the address of the current_node as this now becomes the address of the head pointer
  
}

int main() {

node_t *head = malloc(sizeof(node_t));

head->value = 1;

  for (int i = 2; i < 7; i++){
    add_node_at_end(head, i);
  }

  print_list(head);

  printf("remove first node\n");

  delete_node_at_beginning(&head);

  print_list(head);

  printf("remove node at index 3\n");

  if ( delete_node_at_particular_point(head, 3) < 0)
    delete_node_at_end(head);

  print_list(head);

  printf("remove node at end\n");

  delete_node_at_end(head);

  print_list(head);

  add_node_at_end(head, 10);

  printf("10 added at end\n");

  print_list(head);

  add_node_at_beginning(&head, 20);

  printf("20 added at beginning\n");

  print_list(head);

  if (add_node_at_particular_point(head, 100, 3) < 0)
    add_node_at_end(head, 100);

  printf("100 inserted at index 3\n");

  print_list(head);

  if(delete_node_at_particular_point(head, 6) < 0)
    delete_node_at_end(head);

  printf("used particular point with if statement to remove end\n");

  print_list(head);

  if (add_node_at_particular_point(head, 88, 10) < 0)
    add_node_at_end(head, 88);

  printf("used particular point with if statement to add node at end\n");

  print_list(head);

  return 0;
}


#include <stdlib.h>
#include <stdio.h>

struct node {
  int value;
  struct node* next;
};

typedef struct node node_t;

int number_of_nodes = 0;

// other functions to add:
// add node at beginning - complete
// add node at particular point - complete
// delete node at beginning - complete but needs refactoring
// delete node at end - complete
// delete node at particular point - complete

void delete_node_at_particular_point(node_t *current_node, int index)
{
  int i = 0;

  // traverse linked list until you reach index - 1

  while ( (i != index -1) && (current_node->next != NULL) )
    {
      current_node = current_node->next;
      i++;
    }

  // if current_node->next == NULL then exit the function as we are at the last node and we have a function to delete the last node

  if (current_node->next == NULL)
    {
      // may use this to remove end node
        node_t *tmp;
  
  // have tmp equal the node at index

  tmp = current_node->next;

  // have next pointer of node at index - 1 equal to adress of node at index + 1
  current_node->next = current_node->next->next;

  // now free tmp, which has the address of the node we wish to delete

  free(tmp);

  number_of_nodes--;
  // may use above to remove end node
      
      return;
    }

  // create tmp node

  node_t *tmp;
  
  // have tmp equal the node at index

  tmp = current_node->next;

  // have next pointer of node at index - 1 equal to adress of node at index + 1
  current_node->next = current_node->next->next;

  // now free tmp, which has the address of the node we wish to delete

  free(tmp);

  number_of_nodes--;

  return;

}

// suggested fix for delete_node_at_end
// 

void delete_node_at_end(node_t *current_node)
{
  int i = 1;
  while (i != number_of_nodes-1) // go to penultimate, then set next equal to NULL // need to actually go to end, then go one back
    {
      current_node = current_node->next;
      i++;
    }

    // we are now at penultimate  

  node_t *tmp = current_node->next; // create a tmp node with same address as the end node

  //  printf("size of tmp is %d, size of current_node is %d\n", sizeof(tmp), sizeof(current_node) );

  //  printf(" address of end node in tmp is %d, hardcoded version is %d\n", tmp, current_node->next);

  // printf("the value at that end node is %d from tmp or hardcoded is %d\n", tmp->value, current_node->next->value);

  // go back one step and then set next to null
  

  current_node->next = NULL; // set the next pointer of penultimate node to be NULL, making it the new end node

  //  printf("new end node is value %d\n", current_node->value);
  
  free(tmp); // free tmp, which pointed to the previous end node
  number_of_nodes--;
  return;

}


void print_list(node_t *current_node)
{
  while (current_node->next != NULL)
    {
  int current_value = current_node->value;
  printf(" %d ->", current_value);

  //printf(" the address is %d", &current_value);
  current_node = current_node->next;

    }

  // if it is null the while loop breaks, so we need one more final print

  // value at the very end is
  printf(" %d ->", current_node->value);

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

  // printf("tmp value is %d\n", tmp->value);

  // possible fix current_node = current_node->next
  // current_node->value = new_value

  current_node = current_node->next;
  current_node->value = new_value;

  // printf("current_node value is %d\n", current_node->value);
  number_of_nodes++;
  
  //printf("the address of the end node is %d\n", &new_value);
  return;
}

node_t* add_node_at_beginning(node_t *first_node, int new_value)
{

 node_t *tmp = malloc(sizeof(node_t));

 tmp->value = new_value;

 tmp->next = first_node;

 number_of_nodes++;

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
      // may be used to add node at end

        node_t *tmp = malloc(sizeof(node_t)); // create the new node

  // move the next pointer of the tmp node to point to the same place as the next pointer of the current node
  tmp->next = current_node->next;

  // move the next pointer of the current node to point at the new tmp node we just made
  current_node->next = tmp;

  // set the value for the tmp node we just made
  tmp->value = new_value;

  number_of_nodes++;

  // may be used to add node at end
      
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

  number_of_nodes++;

  return;
}

int main() {

node_t *head = malloc(sizeof(node_t));

head->value = 1;

void delete_node_at_beginning()
{
  node_t *tmp = head;

  head = head->next;

  free(tmp);

  number_of_nodes--;

  return;
  
}


  for (int i = 2; i < 7; i++){
    add_node_at_end(head, i);
  }

  print_list(head);

  head = add_node_at_beginning(head, 20);

  printf("the list below should be equal to the list above, but with 20 added at the start\n");

  print_list(head);

  add_node_at_particular_point(head, 30, 2);

  printf("the list below should be equal to the list above, but with 30 in index 2 (index starts at 0)\n");

  print_list(head);

  // head = head->next;
  //head->value = head->next->value;

  //node_t *tmp = head; // set the value of tmp as being equal to the address of head USE THIS LINE

  //printf("tmp is mem address %d and head is mem address %d\n", tmp, head);
  
  // change the address of head to be the address of the second node

  //head = head->next; // USE THIS LINE

  //printf("head is mem address %d and the second node is mem address %d\n", head, head->next);

  // change the value of the head to be the value of the second node

  // free the memory which tmp points to

  printf("the list below should be the same as the list above, but with 20 removed from the start\n");

  delete_node_at_beginning(); // USE THIS LINE

  //free(tmp); // USE THIS LINE

  print_list(head);

  delete_node_at_end(head);

  printf("the list below should be the same as the list above, but with 6 removed from the end\n");

  print_list(head);

  delete_node_at_end(head);

  print_list(head);

  printf("the list below should be the same as the list above, but with the value that was previously at index 2, removed\n"); 

  delete_node_at_particular_point(head, 2);

  print_list(head);

  //printf("Now testing the add node at end part\n");

  add_node_at_end(head, 50);

  printf("now add 50 at end\n");

  printf("number of nodes is %d\n", number_of_nodes);

  delete_node_at_particular_point(head, 3);

  printf("number of nodes is %d\n", number_of_nodes);



  add_node_at_end(head, 50);

  print_list(head);

    head = add_node_at_beginning(head, 200);

    print_list(head);

    add_node_at_particular_point(head, 35, 2);

    print_list(head);

   delete_node_at_particular_point(head, 3);

   print_list(head);

  return 0;
}

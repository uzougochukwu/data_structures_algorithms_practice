#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// one node in the linked list looks like this
typedef struct Node {
  char word[80]; // a string
  struct Node *next; // a pointer to the next node
} Node;

typedef struct Node Node;

typedef struct List {
  Node *front;
  Node *rear;
} List;

// this function returns a pointer to a newly created node
// note that we set the pointer to the next node to NULL

Node *create_new_node(const char *contents) {
  Node *new_node = malloc(sizeof(Node));

  assert(new_node != NULL);
  strcpy(new_node->word, contents);
  new_node->next = NULL;
  return new_node;

}

// set up an empty list
void initialise_list(List *l) {
  assert(l);
  l->front = l->rear = NULL;
}

// add a node to the front of the list
void add_to_front(List *l, const char *word) {
  Node *item = create_new_node(word);

  // empty list case
  if (!l->front) {
    l->front = l->rear = item;
    return;
  }

  // default case
  item ->next = l-> front;
  l->front = item;
}

// add a node to the rear of the list
void add_to_rear(List *l, const char *word) {
  Node *item = create_new_node(word);

  // empty list case
  if (!l->front) {
    l->front = l->rear = item;
    return;
  }

  // default case
  (l->rear)->next = item;
l-> rear = item;
}

// output the list to the screen
void print_list(const List *l){

  for( const Node *current = l->front; current; current=current->next)
    printf("[%s] ", current->word);
  printf("\n");

}

// delete the node containing the target string
void delete_node(List *l, const char *target) {
  Node *p, *q = NULL;

  // find the node we want to delete
  for (p=l->front; p && strcmp(p->word, target); p=p->next)
    q = p;

  if (p == NULL) {
    printf("could not find the word %s in the list.\n", target);
    return;
  }

  // p now points to the node we want to delete
  // q now points to the node before the one we want to delete

  // store the targets next pointer and delete the target
  Node *link = p->next;
  free(p);

  // handle the case that the target is the front (or equivalently q = NULL)
  if (p==l->front) {
    l->front = link;
    if (l->front == NULL)
      l->rear = NULL;
    return;
  }

  // update the next pointer of the node before the one being deleted
  q->next = link;

  // handle the case that the target is the rear
  if (p == l->rear)
    l->rear = q;
}

// insert a word into a sorted list
void add_sorted(List *l, const char *new_word) {
  Node *p = l->front, *q = NULL;


  // find the node we want to insert after
  for (p=l->front; p && (strcmp(p->word, new_word) < 0); p=p->next)
    q = p;

  // p points to the node we want to insert before
  // q points to the node we want to insert after

  if (q==NULL) {
    add_to_front(l, new_word);
    return;
  }

  if (p==NULL) {
    add_to_rear(l, new_word);
    return;
  }

  // otherwise create the new node
  Node *new_node = create_new_node(new_word);

  // and insert it after q and before p
  new_node->next = p;
  q->next = new_node;
}

// delete all items in the list
void delete_list(List *l) {
  // keeep deleting items from the front of the list until there is nothing left
  while (l->front != NULL) {
    Node *link = (l-> front) ->next;
    free(l->front);
    l->front = link;
  }

  l->rear = NULL;

}

int main() {
  List l;

  // initialise the list
  initialise_list(&l);

  // add some nodes
  add_to_front(&l, "sat");
  add_to_rear(&l, "cat");
  add_to_front(&l, "mat");
  add_to_rear(&l, "hat");

  print_list(&l);
  printf("\n");

  // delete a node
  delete_node(&l, "mat");

  print_list(&l);
  printf("\n");

  // delete the list
  delete_list(&l);

  // add some elements in ascending order
  add_sorted(&l, "sat");
  add_sorted(&l, "cat");
  add_sorted(&l, "hat");
  add_sorted(&l, "mat");
  add_sorted(&l, "bat");
  add_sorted(&l, "rat");

  print_list(&l);
  printf("\n");

  delete_list(&l);

  return 0;

}

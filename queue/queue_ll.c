#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define QUEUE_LENGTH 5
#define EMPTY (-1)
#define QUEUE_EMPTY INT_MIN

typedef struct node {
  int value;
  struct node *next;
} node;

typedef struct{
  node *head;
  node *tail;
} queue;

void init_queue(queue *q){
  q->head=NULL;
  q->tail = NULL;

}

bool enqueue(queue *q, int value){
  // create new node
  node * newnode = malloc(sizeof(node));
  if (newnode == NULL) return false;
  
  newnode->value = value;
  newnode->next = NULL;
  
  // if there is a tail connect tail to this new nod
  if (q->tail != NULL){
    q->tail->next = newnode;
  }

  q->tail = newnode;
  // make sure the head makes sense
  if (q->head ==NULL){
    q->head = newnode;

  }
  return true;
}

int dequeue(queue *q) {
  // check to see if the queue is empty
  if (q->head == NULL) return QUEUE_EMPTY;

  // save the head of the queue
  node *tmp = q->head;

  // save the result we're going to return
  int result = tmp->value;

  // take it off
  q->head = q->head->next;
  if (q->head = NULL){
    q->tail = NULL;
  }

  free(tmp);
  return result;
}

int main(){

  queue q1, q2, q3;

  init_queue(&q1);
  init_queue(&q2);
  init_queue(&q3);

  enqueue(&q1, 80);
  enqueue(&q2, 32);
  enqueue(&q2, 23);
  enqueue(&q2, 988);
  enqueue(&q3, 2);

  int t;
  
  while((t=dequeue(&q2))!= QUEUE_EMPTY){
    printf("t = %d\n", t);
  }

  return 0;
}

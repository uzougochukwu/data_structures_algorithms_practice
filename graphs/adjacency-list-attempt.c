#include <stdio.h>
#include <stdlib.h>

struct node{
  int vertex;
  struct node* next;
};

struct Graph{
  int numVertices;
  struct node** adjLists;
};

int add_node(struct node *root, int value){

struct node *tmp = malloc(sizeof(struct node));
tmp->vertex = value;
root->next = tmp;

return 0;
}

int print_nodes(struct node *root){

  struct node *tmp;

  tmp = root;

  while (tmp->next != NULL){
    printf(" %d -", tmp->vertex);
    tmp=tmp->next;
  }
  printf("%d ", tmp->vertex);

  return 0;
}

int main(){
  char EdgeList[] = {};

  char *arr;
  arr = &EdgeList;
  
struct Graph *MainList = malloc(sizeof(struct Graph));

MainList->numVertices = 0;

MainList->adjLists;

struct node *root1 = malloc(sizeof(struct node));
root1->vertex = 0;

add_node(root1, 1);

print_nodes(root1);

return 0;
}

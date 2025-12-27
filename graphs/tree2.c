#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
} TreeNode;

TreeNode* new_node(int val){
  TreeNode* n = malloc(sizeof(TreeNode));

  n->val = val;
  n->right = NULL;
  n->left = NULL;

  return n;
}

void print_depth_first(TreeNode* root){

  TreeNode* process_stack[100];
  size_t process_stack_num = 0;

  process_stack[0] = root;
  process_stack_num++;

  while (process_stack_num > 0 ){
    TreeNode* current = process_stack[0];
    process_stack_num--;

    printf("%d ", current->val);

    if(current->right != NULL){
      process_stack[process_stack_num] = current->right;
      process_stack_num++;      
    }
    if(current->left != NULL){
      process_stack[process_stack_num] = current->left;
      process_stack_num++;
    }
  }  
}

void print_depth_first_recursive(TreeNode* root){

  TreeNode* current = root;
  printf("%d ", current->val);
  if (current->left != NULL){
    print_depth_first_recursive(current->left);
  }
  if (current->right != NULL){
    print_depth_first_recursive(current->right);
  }
}

void print_breadth_first(TreeNode* root){
  TreeNode* process_queue[100];
  size_t process_queue_num = 0;

  process_queue[0]=root;
  process_queue_num++;

  while (process_queue_num>0){
    int i;
    TreeNode* current = process_queue[0];

    for (i=0;i<process_queue_num-1;i++){
      process_queue[i]=process_queue[i+1];
    }
    process_queue_num--;

    printf("%d ", current->val);

    if( current->left != NULL){
      process_queue[process_queue_num] = current->left;
      process_queue_num++;
  }
    if( current->right != NULL){
      process_queue[process_queue_num] = current->right;
      process_queue_num++;
    }
}
}


int main(){

  TreeNode* root = new_node(0);
  root->left = new_node(1);
  root->right = new_node(2);
  root->left->left = new_node(3);
  root->left->right = new_node(4);

  root->right->left = new_node(5);
  root->right->right = new_node(6);

  print_breadth_first(root);
  

  return 0;
}

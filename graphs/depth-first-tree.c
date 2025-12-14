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
  n->left = NULL;
  n->right = NULL;
  return n;
}
void print_depth_first(TreeNode* root){
  TreeNode* process_stack[100];  // stack of TreeNode pointers, max 100
  size_t process_stack_num = 0;  // keeps track of how many elements in the stack
  process_stack[0] = root;      // first element is the root node
  process_stack_num++;          // increment process_stack_num to show we have 1 element

  while (process_stack_num > 0){ // whilst the process_stack has at least 1 element
    TreeNode* current = process_stack[process_stack_num - 1]; // the current node is taken from the end of the stack
    process_stack_num--;    // decrement process_stack_num as we have taken an element

    printf("%d ", current->val);   // print the current node
  

    if (current->right != NULL){   // check that the right node exists
      process_stack[process_stack_num] = current->right;  // if it does, add it to the stack of TreeNode pointers
      process_stack_num++;      // increment process_stack_num as we have added an element
    }
    if (current->left != NULL){  // check that the left node exists
      process_stack[process_stack_num] = current->left;   // if it does, add it to the stack of TreeNode pointers
      process_stack_num++;    // increment process_stack_num as we have added an element
    }
  }
}
//     0
//   /   \
//  1     2
// / \   / \
// 3 4   5  6

int main(int argc, char* argv[]){

  TreeNode* root = new_node(0);

  root->left = new_node(1);
  root->right = new_node(2);
  
  root->left->left = new_node(3);
  root->left->right = new_node(4);

  root->right->left = new_node(5);
  root->right->right = new_node(6);

  print_depth_first(root);
  
  return 0;
}

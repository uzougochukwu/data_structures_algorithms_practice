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
//     0
//   /   \
//  1     2
// / \   / \
// 3 4   5  6

int main(int argc, char* argv[]){

  TreeNode* root = new_node(0);

  root->left = new_node(1);
  root->right = new_node(2);  

  printf("Root value is %d\n", root->val);
  printf("Left descendant of root is %d\n", root->left->val);
  printf("Right descendant of root is %d\n", root->right->val);
  return 0;
}

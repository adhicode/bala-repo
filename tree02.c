#include <stdio.h>
#include <stdlib.h>

// To execute C, please define "int main()"

typedef struct Node {
  int    data;
  struct Node *left;
  struct Node *right;
} Node_t;

Node_t* newnode(int data)
{
  Node_t *newnode = malloc(sizeof(Node_t));
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  
  return newnode;
}

Node_t* insert(Node_t* node, int data) {
  // 1. If the tree is empty, return a new, single node
  if (node == NULL) {
    return(newnode(data));
  }
  else {
    // 2. Otherwise, recur down the tree
    if (data <= node->data) 
      node->left = insert(node->left, data);
    else 
      node->right = insert(node->right, data);

    return(node); // return the (unchanged) node pointer
  }
}

void printTree(Node_t* node) {
  if (node == NULL) return;

  printTree(node->left);
  printf("%d ", node->data);
  printTree(node->right);
}

// Binary search tree

int main() {
  /* 
  Node_t *node1 = newnode(10);
  */
  Node_t *root = NULL;
  
  root = insert(NULL, 10); 
  root = insert(root, 5); 
  root = insert(root, 15); 
 
  printTree (root);
  return 0;
}


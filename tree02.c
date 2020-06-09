#include <stdio.h>
#include <stdlib.h>

// To execute C, please define "int main()"

typedef struct Node {
  int    data;
  struct Node *left;
  struct Node *right;
} Node;

Node* newnode(int data)
{
  Node *newnode = malloc(sizeof(Node));
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  
  return newnode;
}

Node* insert(Node* node, int data) {
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

void printTree(Node* node) {
  if (node == NULL) return;

  printTree(node->left);
  printf("%d ", node->data);
  printTree(node->right);
}

// Binary search tree

int main() {
  /* 
  Node *node1 = newnode(10);
  */
  Node *root = NULL;
  
  root = insert(NULL, 10); 
  root = insert(root, 5); 
  root = insert(root, 15); 
 
  printTree (root);
  return 0;
}


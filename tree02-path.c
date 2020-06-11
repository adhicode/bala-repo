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
    if (data < node->data) 
      node->left = insert(node->left, data);
    else 
      node->right = insert(node->right, data);

    return(node); // return the (unchanged) node pointer
  }
}

unsigned int maxdepth(Node *root)
{
    unsigned int ldepth = 0;
    unsigned int rdepth = 0;
 
  
    if (root == NULL)
      return 0;
  
    if ((root != NULL) && ((root->left == NULL) && (root->right == NULL)))
      return 1;
    else 
    {  
      ldepth = maxdepth (root->left);
      rdepth = maxdepth (root->right);
      printf("\nnode = %d, ldepth = %d, rdepth = %d", root->data, ldepth, rdepth);
  
      if (ldepth > rdepth)
          return (ldepth + 1);
      else
        return (rdepth + 1);
    }
}


/*
 Given a binary tree, print out all of its root-to-leaf
 paths, one per line. Uses a recursive helper to do the work.
*/
void printPaths(Node* node) {
  int path[1000];

  printPathsRecur(node, path, 0);
}

/*
 Recursive helper function -- given a node, and an array containing
 the path from the root node up to but not including this node,
 print out all the root-leaf paths.
*/
void printPathsRecur(Node* node, int path[], int pathLen) {
  if (node==NULL) return;

  // append this node to the path array
  path[pathLen] = node->data;
  pathLen++;

  // it's a leaf, so print the path that led to here
  if (node->left==NULL && node->right==NULL) {
    printArray(path, pathLen);
  }
  else {
  // otherwise try both subtrees
    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen);
  }
}

// Utility that prints out an array on a line.
void printArray(int ints[], int len) {
  int i;
  for (i=0; i<len; i++) {
    printf("%d ", ints[i]);
  }
  printf("\n");
}

// ascending order
void printTree(Node* node) {
  if (node == NULL) return;

  printTree(node->left);
  printf("%d ", node->data);
  printTree(node->right);
}

int minvalue(Node* node) {
  Node* current = node;

  // loop down to find the leftmost leaf
  while (current->left != NULL) {
    current = current->left;
  }

  return(current->data);
}

void printPostorder(Node* node) {
  if (node == NULL) 
    return;

  if ((node != NULL) && ((node->left == NULL) && (node->right == NULL)))
  {
    printf("%d ", node->data);
    return ;
  }
  else
  {
  // first recur on both subtrees
  printTree(node->left);
  printTree(node->right);

  // then deal with the node
  printf("%d ", node->data);
  }
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
  root = insert(root, 3); 
  root = insert(root, 1); 
  root = insert(root, 4); 
  root = insert(root, 0); 
  printTree (root);
  
  printf("\nmaxdepth = %d", maxdepth(root));
  
  printf("\nmin = %d", minvalue(root));
  printf("\n");
  printPostorder(root);
  
  return 0;
}


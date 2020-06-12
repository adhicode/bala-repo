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

 int maxvalue(Node* node) {
   Node* current = node;
 
   // loop down to find the leftmost leaf
   while (current->right != NULL) {
     current = current->right;
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
 

// Utility that prints out an array on a line.
void printArray(int ints[], int len) {
  int i;
  for (i=0; i<len; i++) {
    printf("%d ", ints[i]);
  }
  printf("\n");
  return;
}

/*
 Recursive helper function -- given a node, and an array containing
 the path from the root node up to but not including this node,
 print out all the root-leaf paths.
*/
void printPathsRecur(Node* node, int path[], int pathLen) {
 
  printf("stack frame pathLen %d \n", pathLen);
  if (node==NULL) return;

  // append this node to the path array
  path[pathLen] = node->data;
  pathLen++;

  // it's a leaf, so print the path that led to here
  if (node->left==NULL && node->right==NULL) {
    printf("Before path print %d \n", pathLen);
    printArray(path, pathLen);
  }
  else {
  // otherwise try both subtrees
    printf("Before left %d \n", pathLen);
    printPathsRecur(node->left, path, pathLen);
    printf("Before right %d \n", pathLen);
    printPathsRecur(node->right, path, pathLen);
  }
  return;
}


void printPaths(Node* node) {
  int path[1000];

  printPathsRecur(node, path, 0);
}

void mirror(Node* node) {
  if (node==NULL) {
    return;
  }
  else {
    Node* temp;

    // do the subtrees
    mirror(node->left);
    mirror(node->right);

    // swap the pointers in this node
    temp = node->left;
    node->left = node->right;
    node->right = temp;
  }
} 



#define true (1)
#define false (0)

/*
 Returns true if the given tree is a BST and its
 values are >= min and <= max.
*/
int isBSTUtil(Node* node, int min, int max)
{
  if (node==NULL) return(true);

  // false if this node violates the min/max constraint
  if (node->data<min || node->data>max) return(false);

  // otherwise check the subtrees recursively,
  // tightening the min or max constraint
  return
    isBSTUtil(node->left, min, node->data) &&
    isBSTUtil(node->right, node->data+1, max);
}

int isBST2(Node* node, int min, int max) {
  return(isBSTUtil(node, min, max));
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
   root = insert(root, 7); 
   root = insert(root, 12); 
   root = insert(root, 22); 
   printTree (root);
   
   printf("\nmaxdepth = %d", maxdepth(root));
   
   printf("\nmin = %d", minvalue(root));
   printf("\nmax = %d", maxvalue(root));
   printf("\n");
   printPostorder(root);
   printf("\n");
   
   printPaths(root);
   //mirror(root);
   printTree (root);
   
   printf("\n isBST = %d", isBST2(root, minvalue(root), maxvalue(root)));
   printf("\n");
   
   return 0;
 }
 

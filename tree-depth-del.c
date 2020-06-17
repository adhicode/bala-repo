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
unsigned int mindepth(Node *root)
 {
     unsigned int ldepth = 0;
     unsigned int rdepth = 0;
  
   
     if (root == NULL)
       return 0;
   
     if ((root != NULL) && ((root->left == NULL) && (root->right == NULL)))
       return 1;
     else 
     {  
       ldepth = mindepth (root->left);
       rdepth = mindepth (root->right);
       printf("\nnode = %d, ldepth = %d, rdepth = %d", root->data, ldepth, rdepth);
   
       if (ldepth < rdepth)
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

 Node* minvalueNode(Node* node) {
   Node* current = node;
 
   // loop down to find the leftmost leaf
   while (current->left != NULL) {
     current = current->left;
   }
 
   return(current);
 }

 Node* maxvalueNode(Node* node) {
   Node* current = node;
 
   // loop down to find the leftmost leaf
   while (current->right != NULL) {
     current = current->right;
   }
 
   return(current);
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


Node* Delete(Node *root, int data) {
  if (root == NULL) {
     return NULL;
  }
  if (data < root->data) {  // data is in the left sub tree.
      root->left = Delete(root->left, data);
  } else if (data > root->data) { // data is in the right sub tree.
      root->right = Delete(root->right, data);
  } else {
     // case 1: no children
     if (root->left == NULL && root->right == NULL) {
        free(root); // wipe out the memory, in C, use free function
        root = NULL;
     }
     // case 2: one child (right)
     else if (root->left == NULL) {
        struct Node *temp = root; // save current node as a backup
        root = root->right;
        free(temp);
     }
     // case 3: one child (left)
     else if (root->right == NULL) {
        struct Node *temp = root; // save current node as a backup
        root = root->left;
        free(temp);
     }
     // case 4: two children
     else {
        struct Node *temp = minvalueNode(root->right); // find minimal value of right sub tree
        root->data = temp->data; // duplicate the node
        root->right = Delete(root->right, temp->data); // delete the duplicate node
     }
  }
  return root; // parent node can update reference
}

int hasPathSum(Node* node, int sum) {
  // return true if we run out of tree and sum==0
  if (node == NULL) {
    return(sum == 0);
  }
  else {
  // otherwise check both subtrees
    //int subSum = sum - node->data;
    return(hasPathSum(node->left, (sum - node->data)) ||
           hasPathSum(node->right, (sum - node->data)));
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
   root = insert(root, 7); 
   //root = insert(root, 12); 
   //root = insert(root, 22); 
   printTree (root);
   
   printf("\nmaxdepth = %d", maxdepth(root));
   printf("\nmindepth = %d", mindepth(root));
   
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
   
   printf("\n hasPathSum 15 = %d", hasPathSum(root, 15));
   printf("\n");
   
   printf("\n hasPathSum 47 = %d", hasPathSum(root, 47));
   printf("\n");
   
   printf("\n hasPathSum 19 = %d", hasPathSum(root, 19));
   printf("\n");
   
   Delete(root, 0);
   printTree (root);
   root = insert(root, 0); 
   Delete(root, 10);
   printf("\n");
   printf("root key = %d \n", root->data);
   printTree (root);
   printf("\n");
   
   Delete(root, 12);
   printf("\n");
   printf("root key = %d \n", root->data);
   printTree (root);
   printf("\n");
   return 0;
 }
 

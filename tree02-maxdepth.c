#include <stdio.h>
#include <stdlib.h>

// To execute C, please define "int main()"

typedef struct tnode{
  int    data;
  struct tnode *left;
  struct tnode *right;
} Node;

Node* newnode(int data)
{
  Node *newnode = malloc(sizeof(Node));
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  
  return newnode;
}
/*
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
*/

Node* insert(Node* root, Node *node) {
	// 1. If the tree is empty, return a new, single node
	if (!root) {
		root = node;
		root->left = NULL;
		root->right = NULL;
	}
	else {
	// 2. Otherwise, recur down the tree
	if (node->data < root->data) 
		root->left = insert(root->left, node);
	// == & >
	else 
		root->right = insert(root->right, node);
	}
	return(root); // return current stack node ptr
}

unsigned int maxdepth(Node *root)
{
    unsigned int ldepth = 0;
    unsigned int rdepth = 0;
  
    if (root == NULL)
      return 0;
  
    else 
    {  
     ldepth = maxdepth (root->left);
     rdepth = maxdepth (root->right);

     // else - ldepth >= rdepth  
     return ((ldepth < rdepth) ? (rdepth + 1): (ldepth + 1));

      /*
      if (ldepth > rdepth)
          return (ldepth + 1);
      else 
		if (ldepth < rdepth)
			return (rdepth + 1);
      		else
      		// ldepth == rdepth. incr ldepth or rdepth 
      			return (rdepth + 1);
	*/
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
 
  root = insert(NULL, newnode(10)); 
  root = insert(root, newnode(5)); 
  root = insert(root, newnode(15)); 
  root = insert(root, newnode(3)); 
//  root = insert(root, 5); 
 // root = insert(root, 15); 
 
  printTree (root);
  
  printf("\nmaxdepth = %d", maxdepth(root));
  return 0;
}


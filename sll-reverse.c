#include <stdio.h>

typedef struct Node {
  int value;  
  struct Node *next; //stores the pointer to next
} Node;

void print_list(Node *root){
  while(root){
    printf("%d\n", root->value);
    root = root->next;
  }
}

Node* reverse(Node *current){
  Node *prev = NULL;
  Node *next = NULL;
  Node *ret;
  
  while(current){
    next = current->next; // next points to 2
    current->next = prev; // 1 points to null
    prev = current; // prev points to 1
    ret = current;
    /* if (!next)
	return current;  */ 
    current = next; // current points to 2
  }

  return ret;
}

int main(){
 Node n1 = {1, NULL};
 Node n2 = {2, &n1};
 Node n3 = {3, &n2};
 /*
 Node root[3] = {
                  {&root[1],1}, // root[0] 
                  {&root[2],2}, 
                  {NULL,3}
                  };

*/ 
 Node *root = &n3;
 print_list(root);
  printf("root& %x, root[0]& %x, root[1]& %x, root[2]& %x \n", root, &root[0], &root[1], &root[2]);
 //Node *result = reverse(&n3);
 Node *result = reverse(&root[0]);
 print_list(result);
}

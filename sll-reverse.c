# include <stdio.h>

typedef struct Node {
  struct Node *next; //stores the pointer to next
  int value;  
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
    current = next; // current points to 2
  }


  return ret;
}

int main(){
 Node n1 = {0, 1};
 Node n2 = {&n1, 2};
 Node n3 = {&n2, 3};
 Node root[3] = {
                  {&root[1],1}, 
                  {&root[2],2}, 
                  {NULL,3}
                  };
 
 //Node *root = &n3;
 print_list(root);
  printf("root& %x, root[0]& %x, root[1]& %x, root[2]& %x \n", root, &root[0], &root[1], &root[2]);
 //Node *result = reverse(&n3);
 Node *result = reverse(&root[0]);
 print_list(result);
}

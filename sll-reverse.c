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
  Node *last = NULL;
  Node *next = NULL;
  Node *ret;
  
  while(current){
    next = current->next; // next points to 2
    current->next = last; // 1 points to null
    last = current; // last points to 1
    ret = current;
    current = next; // current points to 2
  }


  return ret;
}

int main(){
 Node n1 = {0, 1};
 Node n2 = {&n1, 2};
 Node n3 = {&n2, 3};
 
 Node *root = &n3;
 //print_list(root);
 Node *result = reverse(&n3);
 print_list(result);
}

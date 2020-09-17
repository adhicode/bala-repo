#include<stdio.h>
#include<stdlib.h>

typedef struct dll_node
{
	int key;
	struct dll_node *front;
	struct dll_node *back;
}DLL_Node;

#define MAGIC 0xBEAFDEAD

//DLL_Node* insert(DLL_Node *head, int key);
DLL_Node* insert(int key);
void print_dll(DLL_Node *head);
DLL_Node* create_node();

DLL_Node* head = NULL;


DLL_Node* (*func_ptr_create)(void);

DLL_Node* create_node()
{
	DLL_Node *anode;	
	anode = (DLL_Node*) malloc(sizeof(DLL_Node));
	anode->key = MAGIC;
	anode->front = NULL;
	anode->back = NULL;
	return anode;	
}

DLL_Node* insert(int key)
{
	DLL_Node *newnode;	
	if (!head)
	{
		// head = create_node();
		head = func_ptr_create();
	}
	else
	{	
		newnode = func_ptr_create();
		// newnode = create_node();
		newnode->key = key;

		newnode->back = head;
		newnode->front = head->front;
		if (head->front)
			(head->front)->back = newnode;
		else 
			newnode->back = head;
		head->front = newnode;	
	}
	return head;
}

void print_dll(DLL_Node *head)
{
	DLL_Node *temp = head;	
	while (temp)
	{
		printf("key %x ", temp->key);
		if (temp->front)
			printf("front %x ", (temp->front)->key);
		if (temp->back)
			printf("back %x ", (temp->back)->key);
		printf("\n");
		temp = temp->front;
	}

	return;
}

int main()
{
	int key_db[5] = {0x1, 0x2, 0x3, 0x4, 0x5};
	int count = 0;
	void (*func_ptr)(DLL_Node *);
	void (*func_ptr_arr[10])(DLL_Node *);

	func_ptr_create = create_node;
	func_ptr_arr[0] = print_dll;
	func_ptr = print_dll;
	for (; count < 5; count++)
		insert(key_db[count]);
	print_dll(head);
	func_ptr(head);
	func_ptr_arr[0](head);
}

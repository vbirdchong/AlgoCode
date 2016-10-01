
/*
Subject:

Implement an algorithm to delete a node in the middle of a single linked list,
 given only access to that node.

EXAMPLE

Input: the node ‘c’ from the linked list a->b->c->d->e Result: nothing is returned, 
but the new linked list looks like a->b->d->e

Note: 
Please be careful, the node need to delete maybe the first head,
middle node, the last node or maybe its equal to NULl .
*/

#include <iostream>

using namespace std;

typedef struct node{
	int data;
	node* next;
}node;


node* init(int a[], int n){
	node *head, *p;
	
	if(a == NULL || n < 1)
		return NULL;
	
	for(int i = 0; i < n; ++i){
		node *new_node = new node();
		new_node->data = a[i];
		
		if(0 == i){
			head = new_node;
			p = new_node;
		}
		
		p->next = new_node;
		p = new_node;
	}
	return head;
}

void remove(node **head){
	node **curr = head;
	
	while(*curr){
		node *entry = *curr;
		if(entry->next != NULL){
			*curr = entry->next;
			delete entry;
		}
		else{
			delete entry;
			*curr = NULL;
		}
	}
}

void print_node(node* head){
	while(head){
		cout << "data: " << head->data << endl;
		head = head->next;
	}
}

bool remove_by_node_adress(node *c){

	// we need care some cases
	// 1) node = NULL
	if (c == NULL)
		return false;
	else if(c->next == NULL) // 2) the last node, here we do nothing
		return false;
	// 3) the first node or the middle node
	else{
		node *d = c->next;
		c->data = d->data;
		c->next = d->next;
		delete d;
		return true;
	}
}


int main(){
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int n = 10;
	
	node *head = init(a, n);
	print_node(head);
	
	int cc = 3;
	node* c = head;
	for(int i = 0; i < cc; ++i){
		c = c->next;
	}
	
	if(remove_by_node_adress(c)){
		print_node(head);
	}
	
	remove(&head);
	print_node(head);
}
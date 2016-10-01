
/*
You have two numbers represented by a linked list, where each node contains a single digit. 
The digits are stored in reverse order, such that the 1’s digit is at the head of the list. 
Write a function that adds the two numbers and returns the sum as a linked list.

EXAMPLE

Input: (3 -> 1 -> 5), (5 -> 9 -> 2)

Output: 8 -> 0 -> 8

expound like this:
513 + 295 = 808 

*/

#include <iostream>

using namespace std;

typedef struct node{
	int data;
	node *next;
}node;


node* init(int a[], int n){
	node *head, *p;
	
	if(a == NULL || n < 1){
		return NULL;
	}
	
	for(int i = 0; i < n; ++i){
		node *new_node = new node();
		new_node->data = a[i];
		
		if(i == 0){
			head = new_node;
			p = new_node;
			continue;
		}
		
		p->next = new_node;
		p = new_node;
	}
	
	return head;
}

void remove(node **head){
	node **cur = head;
	
	while(*cur){
		node *entry = *cur;
		if (entry->next != NULL){
			*cur = entry->next;
			delete entry;
		}
		else{
			delete entry;
			*cur = NULL;
		}
	}
}

void print(node *head){
	while(head){
		cout << "value = " << head->data << endl;
		head = head->next;
	}
}

node* add_link(node* a, node* b){
	if (a == NULL && b == NULL){
		return NULL;
	}
	if(a == NULL){
		return b;
	}
	if(b == NULL){
		return a;
	}
	
	node* head = NULL;
	node* q = NULL;
	int c = 0;
	while(a && b){
		node* p = new node();
		int t = a->data + b->data + c;
		c = t / 10;
		p->data = t % 10;
		if(head == NULL){
			head = p;
			q = p;
		}
		else{
			q->next = p;
			q = p;
		}
		a = a->next;
		b = b->next;
	}
	
	// the number of a is bigger than b, we need to continue to add the digit
	while(a){
		node* p = new node();
		int t = a->data + c;
		c = t / 10;
		p->data = t % 10;
		
		q->next = p;
		q = p;
		
		a = a->next;
	}

	// the number of b is bigger than a, we need to continue to add the digit
	while(b){
		node* p = new node();
		int t = b->data + c;
		c = t / 10;
		p->data = t % 10;
		
		q->next = p;
		q = p;
		
		b = b->next;
	}
	
	if (c){
		node* p = new node();
		p->data = c;
		q->next = p;
	}
	
	return head;
}

int main(){
	int a[] = {3, 1, 5, 5};
	int b[] = {5, 9, 2, 5, 6};
	
	node* aa = init(a, 4);
	//print(aa);
	node* bb = init(b, 5);
	//print(bb);
	
	node* add_val = add_link(aa, bb);
	print(add_val);
	
	return 0;
}

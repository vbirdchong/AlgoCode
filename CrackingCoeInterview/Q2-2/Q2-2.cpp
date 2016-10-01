
#include <iostream>

//Subject:
//Implement an algorithm to find the nth to last element of a singly linked list.

using namespace std;

typedef struct node{
	int data;
	node *next;
}node;

node* init(int*a, int n){
	node* head;
	node* p;
	
	for(int i = 0; i < n; ++i){
		node* new_node = new node();
		new_node->data = a[i];
		
		if(0 == i){
			head = new_node;
			p = new_node;
			continue;
		}
		p->next = new_node;
		p = new_node;
	}
	return head;
}

void remove(node** head){
	node** curr = head;
	
	while(*curr){
		node* entry = *curr;
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

node* find_Nth_to_last(node *head, int n){
	if (head == NULL || n < 1)
		return NULL;
	
	node *p = head;
	node *q = head;
	
	while(n > 0 && q){
		q = q->next;
		n--;
	}
	
	if(n > 0)
		return NULL;
	
	// the distance between q and p keeps 'n', when q = null, then we are also get the Nth to the last value
	// by p;
	while(q){
		q = q->next;
		p = p->next;
	}
	
	return p;
}

int main(){
	
	int a[] = {1,2,3,4,5,6,7};
	int last_N = 2;
	node *head = init(a, 7);
	node *find_the_value = find_Nth_to_last(head, last_N);
	cout << "the last N=" << last_N << " the value = " << find_the_value->data << endl;
	
	remove(&head);
	return 0;
}

/*
Subject:

Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.

DEFINITION

Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list.

EXAMPLE

Input: A -> B -> C -> D -> E -> C [the same C as earlier]

Output: C


*/

#include <iostream>
#include <map>

using namespace std;

typedef struct node{
	int data;
	node *next;
}node;


node *init(int a[], int n, int m){
	node *head = NULL, *p = NULL, *q = NULL;
	
	for(int i = 0; i < n; i++){
		node *new_node = new node();
		new_node->data = a[i];
		
		if(i == 0){
			head = p = new_node;
			continue;
		}
		if(i == m){
			// save the start loop node
			q = new_node;
		}
		
		p->next = new_node;
		p = new_node;
	}
	
	// set the tail node pointer point to the loop start node.
	p->next = q;
	return head;
}


map<node*, bool> hash;
node* loopstart(node* head){
	while(head){
		if(hash[head])
			return head;
		else{
			hash[head] = true;
			head = head->next;
		}
	}
	return head;
}


int main(){
	int n = 10, m = 1;
	int a[] = {3,2,1,3,5,6,2,6,3,1};
	
	node *head = init(a, n, m);
	node *p = loopstart(head);
	if (p){
		cout << "Find the data: " << p->data << endl;
	}

	return 0;
}


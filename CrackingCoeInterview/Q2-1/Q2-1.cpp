
#include <cstring>
#include <iostream>

using namespace std;

typedef struct node{
  int data;
  node *next;
}node;

int hash[100] = {0};

node* init(int* a , int n)
{
  node* head;
  node* p;
  for (int i = 0; i < n; ++i)
  {
    node *nd = new node();
    nd->data = a[i];
    if (i == 0)
    {
      head = nd;
      p = nd;
      continue;
    }
    p->next = nd;
    p = nd;
  }

  return head;
}

bool removeDuplicate(node* head)
{
  if (NULL == head)
    return false;

  node* p = head, *q = head->next;
  hash[head->data] = 1;

  while(q)
  {
    if (hash[q->data] == 1)
    {
      node* tmp = q;
      p->next = q->next;
      q = p->next;
      delete tmp;
    }
    else
    {
      hash[q->data] = 1;
      p = q;
      q = q->next;
    }
  }

  return true;
}

// 传入的值使用二级指针
void remove(node** head)
{
  cout << "remove: head: " << *head << endl;
  node ** cur = head;
  
  while(*cur){
	node *entry = *cur;
	if(entry->next != NULL){
		*cur = entry->next;
		delete entry;
	}
	else{
		delete entry;
		*cur = NULL;
	}
  }
}

void printout(node* head)
{
  node *p = head;
  while(p)
  {
    cout << p->data << " address: " << p << " next:" << p->next << endl;
    p = p->next;
  }
}
int main()
{
  memset(hash, 0, sizeof(hash));
  int n = 10;
  int a[] = {1,2,3,4,5,6,7,2,9,0}; 

  node* head = init(a, 10);
  removeDuplicate(head);
  printout(head);

  remove(&head);
  printout(head);

  return 0;
}



// 141. Linked List Cycle

// Given a linked list, determine if it has a cycle in it.

// Follow up:
// Can you solve it without using extra space?


#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if (head == NULL){
            return false;
        }
        else{
            while((fast != NULL) && (fast->next != NULL)){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast){
                    return true;
                }
            }
            return false;
        }
    }


    void printListNode(ListNode *node){
        if (node == NULL)
        {
            cout << "No val in node" << endl;
        }
        else{
            ListNode *ptr = node;
            while(ptr != NULL){
                cout << "Node val:" << ptr->val << endl;
                ptr = ptr->next;
            }
        }
    }
};



int main(int argc, char const *argv[])
{
    Solution l;
    ListNode *head = new ListNode(0);
    ListNode *ptr = head;

    ListNode *testNode = new ListNode(6);
    ListNode *enterNode = NULL;

    for (int i = 1; i < 5; ++i)
    {
        ListNode *newNode = new ListNode(i);
        if (i == 3)
        {
            enterNode = newNode;
        }
        ptr->next = newNode;
        ptr = newNode;
    }

    ptr->next = testNode;
    testNode->next = enterNode;

    // l.printListNode(head);
    cout << "Has cycle: " << l.hasCycle(head) << '\n';

    return 0;
}
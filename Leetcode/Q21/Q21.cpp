
/*
21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL){ return NULL; }
        if (l1 == NULL && l2 != NULL){ return l2; }
        if (l1 != NULL && l2 == NULL){ return l1; }

        ListNode *newListNode = NULL;
        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;
        ListNode *ptrToNew = newListNode;
        while(ptr1 != NULL || ptr2 != NULL){
            if (ptr1 == NULL) {
                ptrToNew->next = ptr2;
                break;
            }

            if (ptr2 == NULL) {
                ptrToNew->next = ptr1;
                break;
            }
            
            if (ptr1->val < ptr2->val){
                
                if (newListNode == NULL) {
                    newListNode = ptr1;
                    ptrToNew = newListNode;
                }
                else{
                    ptrToNew->next = ptr1;
                    ptrToNew = ptr1;
                }
                
                ptr1 = ptr1->next;
            }
            else {
                
                if (newListNode == NULL) {
                    newListNode = ptr2;
                    ptrToNew = newListNode;
                }
                else {
                    ptrToNew->next = ptr2;
                    ptrToNew = ptr2;
                }

                ptr2 = ptr2->next;
            }

        }

        print(newListNode);
        return newListNode;
    }

    ListNode* mergeLists(ListNode *l1, ListNode *l2) {

        if (NULL == l1) {return l2;}
        if (NULL == l2) {return l1;}

        ListNode *head = NULL;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }

        ListNode *ptr = head;
        while(l1 && l2) {
            if (l1->val < l2->val) {
                ptr->next = l1;
                ptr = l1;
                l1 = l1->next;
            }
            else {
                ptr->next = l2;
                ptr = l2;
                l2 = l2->next;
            }
        }

        if (l1) {
            ptr->next = l1;
        }
        else {
            ptr->next = l2;
        }
        return head;
    }

    void addNode(ListNode *head, ListNode *src, ListNode *pointShift){
        if (NULL != head) {
            pointShift->next = src;
            pointShift = src;
        }
        else{
            head = src;
            pointShift = head;
        }
    }


    void print(ListNode *l1, ListNode *l2){
        if(NULL != l1){
            cout << "L1 node:\n";
            ListNode *tmp = l1;
            while(tmp != NULL){
                cout << tmp->val << '\n';
                tmp = tmp->next;
            }
        }
        if(NULL != l2){
            cout << "L2 node:\n";
            ListNode *tmp = l2;
            while(tmp != NULL){
                cout << tmp->val << '\n';
                tmp = tmp->next;
            }
        }
    }

    void print(ListNode *l1){
        if(NULL != l1){
            cout << "new node:\n";
            ListNode *tmp = l1;
            while(tmp != NULL){
                cout << tmp->val << '\n';
                tmp = tmp->next;
            }
        }
    }
};


int main()
{
    ListNode l1(1);
    ListNode l2(0);

    ListNode *ptr1 = &l1;
    for (int i = 3; i < 9; i){
        ListNode *tmp = new ListNode(i);
        ptr1->next = tmp;
        ptr1 = tmp;
        i += 2;
    }


    ListNode *ptr2 = &l2;
    for (int i = 4; i < 10; i){
        ListNode *tmp = new ListNode(i);
        ptr2->next = tmp;
        ptr2 = tmp;
        i += 3;
    }
    

    Solution sol;
    sol.print(&l1, &l2);
    //sol.mergeTwoLists(&l1, &l2);
    sol.mergeLists(&l1, &l2);
    
    return 0;
}


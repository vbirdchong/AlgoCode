
/* 
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

*/

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {val = x;}
}

public class RemoveNthFromEnd19 {

    public RemoveNthFromEnd19() {}

    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        int length = 0;
        ListNode first = head;
        while (first != null) {
            first = first.next;
            length++;       // get the total length
        }

        length = length - n;
        first = dummy;
        while(length > 0) {
            first = first.next;
            length--;
        }
        first.next = first.next.next; // skip the node which need to delete
        return dummy.next;

    }
    
    public static void main(String[] args) {
        ListNode head = new ListNode(0);
        ListNode current = head;
        for (int i = 1; i <=5; i++) {
            ListNode val = new ListNode(i);
            if (i == 1) {
                head = val;
                current = head;
            } else {
                current.next = val;
                current = val;
            }
        }

        ListNode test = head;
        while (test != null) {
            System.out.println(test.val);
            test = test.next;
        }

        RemoveNthFromEnd19 testObject = new RemoveNthFromEnd19();
        ListNode ret = testObject.removeNthFromEnd(head, 2);
        while (ret != null ) {
            System.out.println(ret.val);
            ret = ret.next;
        }
    }
}
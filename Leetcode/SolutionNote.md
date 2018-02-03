# Solution Note

## 1. Two Sum
### Description
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]. 

[5,1,2,3,2,4]
4
return [1,3]

### Solution 1

暴力搜索，进行循环查找，复杂度O($n^2$)

```
    public int[] twoSum2(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] == target - nums[i]) {
                    return new int[] {i,j};
                }
            }
        }

        throw new IllegalArgumentException("Nothing");
    }
```

### Solution 2

使用hash表，将数组中的值和下标进行key-value的mapping。第一次循环时进行map的创建，第二次循环则直接可以查找，将复杂度降到O(n)。

```
    public int[] twoSum3(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement) && map.get(complement) != i) {
                return new int [] {i, map.get(complement)};
            }
        }

        throw new IllegalArgumentException("No two sum solution");
    }
```

---
## 283. Move Zeroes

### Description
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

### Solution
由于添加到最后的值是固定的，都为0，那只需要将数组中非0的值往前排列即可，最后将0添加上。
```
public void moveZeroes(int[] nums) {
        int cursor = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[cursor++] = nums[i];
            }
        }

        while (cursor < nums.length) {
            nums[cursor++] = 0;
        }
    }
```

---
## 19. Remove Nth Node From End of List

### Description

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

### Solution1
先遍历整个列表，知道它的长度。再次遍历列表，但长度只需要 *len(list) - n*，最后将要删除的点进行跳过即可。

```
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
```

### Solution2
设置两个指针，让第一个指针领先于第二个指针n的间隔，然后两个指针同时进行移动。当第一个指针到达null的时候，第二个指针正好位于要删除的节点的上一个位置，
修改第二个指针的next节点，即可删除需要删除的节点。

![原理](https://leetcode.com/media/original_images/19_Remove_nth_node_from_end_of_listB.png)

```
    public ListNode removeNthFromEnd2(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode first = dummy;
        ListNode second = dummy;

        for (int i = 1; i <= n+1; i++) {
            first = first.next;
        }

        while (first != null) {
            first = first.next;
            second = second.next;
        }

        second.next = second.next.next;
        return dummy.next;
    }
```
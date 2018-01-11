import java.sql.Array;
import java.util.Arrays;

/* 35. Search Insert Position

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0 */

public class SearchInsertPosition {
    public SearchInsertPosition() {
    }

    public int searchInsert(int[] nums, int target) {
        if (nums.length == 0 || target < nums[0] ) return 0;
        if (target > nums[nums.length - 1]) return nums.length;

        int ret = Arrays.binarySearch(nums, target);
        if (ret < 0) {
            while(true) {
                ret = Arrays.binarySearch(nums, --target);
                if (ret < 0) continue;
                else return(ret + 1); 
            }
        }

        return ret;
    }


    public static void main(String[] args) {
        SearchInsertPosition test = new SearchInsertPosition();
        int[] nums = {};
        System.out.print(nums.length);
        int target = 5;
        System.out.print(test.searchInsert(nums, target));
    }
}
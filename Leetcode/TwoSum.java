import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/* 
1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]. 

[5,1,2,3,2,4]
4
return [1,3]
*/

public class TwoSum {
    public TwoSum() {}

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

    public int[] twoSum(int[] nums, int target) {
        int[] ret = new int[2];
        for (int i = 0; i < nums.length; i++) {
            int first = nums[i];
            int seconde = target - first;
            int j = i + 1;
            boolean found = false;
            ret[0] = i;
            for (; j < nums.length; j++) {
                if (nums[j] == seconde) {
                    found = true;
                    ret[1] = j;
                    break;
                }
            }
            if (found) break;
        }
        return ret;
    }

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

    public static void main(String[] args) {
        TwoSum test = new TwoSum();
        int[] nums = {2,2,8,3,4};
        int target = 4;
        int[] ret = test.twoSum2(nums, target);
        for (int var : ret) {
            System.out.print(var);
        }
    }
}
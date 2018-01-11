package com.company;

//
//Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//
//        For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
//        the contiguous subarray [4,-1,2,1] has the largest sum = 6.

/*
解答来源
https://discuss.leetcode.com/topic/5000/accepted-o-n-solution-in-java/2
this problem was discussed by Jon Bentley (Sep. 1984 Vol. 27 No. 9 Communications of the ACM P885)

        the paragraph below was copied from his paper (with a little modifications)

        algorithm that operates on arrays: it starts at the left end (element A[1]) and scans through to the right end (element A[n]), keeping track of the maximum sum subvector seen so far. The maximum is initially A[0]. Suppose we've solved the problem for A[1 .. i - 1]; how can we extend that to A[1 .. i]? The maximum
        sum in the first I elements is either the maximum sum in the first i - 1 elements (which we'll call MaxSoFar), or it is that of a subvector that ends in position i (which we'll call MaxEndingHere).

        MaxEndingHere is either A[i] plus the previous MaxEndingHere, or just A[i], whichever is larger.
*/

/**
 * Created by chonchen on 2017/10/20.
 */
public class Solution {

    public int maxSubArray(int[] nums) {
        int maxSofar = nums[0];
        int maxEndingHere = nums[0];

        for (int i = 1; i < nums.length; i++) {
            // 比较到目前为止最大的结果，在加上后一位数后的变化情况，如果是有利的趋势，则把最大值重新赋值，否则保持不变
            maxEndingHere = Math.max(maxEndingHere + nums[i], nums[i]);
            // 比较当前整体的最大值 maxSorfar 和上面值得结果，取最大值
            maxSofar = Math.max(maxEndingHere, maxSofar);
        }

        return maxSofar;
    }

    public int maxData(int[] A) {
        int max = A[0];
        int leftMax = A[0];

        for (int i = 1; i < A.length; i++) {
            leftMax = Math.max(leftMax + A[i], A[i]);
            max = Math.max(max, leftMax);
        }
        return max;
    }
}

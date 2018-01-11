package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        testCase1();
    }

    private static void testCase1() {
        Solution solution = new Solution();

        int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
        System.out.println(solution.maxData(nums));
    }
}

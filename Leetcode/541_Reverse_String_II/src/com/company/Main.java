package com.company;

public class Main {

    public static void main(String[] args) {

        Solution solution = new Solution();
        String str1 = "abcdef";
        int k1 = 4;

        // test
        test("fedcba", solution.reverseStr2(str1, 7));
        test("dcbaef", solution.reverseStr2(str1, 4));
        test("edcbaf", solution.reverseStr2(str1, 5));
        test("bacdfe", solution.reverseStr2(str1, 2));

        test("2134657809abdc", solution.reverseStr2("1234567890abcd", 2));
        test("abcdefg12345687959621", solution.reverseStr2("edcbafg12378654959621", 5));
    }

    private static void test(String s1, String s2) {
        if (s1.equals(s2)) {
            System.out.println("Pass ->exp:" + s1 + ", ret:" + s2);
        } else {
            System.out.println("Fail ->exp:" + s1 + ", ret:" + s2);
        }
    }
}

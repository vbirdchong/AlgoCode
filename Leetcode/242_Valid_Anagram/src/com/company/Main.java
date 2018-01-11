package com.company;


public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println( solution.isAnagram("hello", "world"));
        System.out.println( solution.isAnagram2("hello", "llohe"));
        System.out.println( solution.isAnagram3("hello", "llohe"));
    }
}

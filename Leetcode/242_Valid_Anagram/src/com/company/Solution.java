package com.company;

//Given two strings s and t, write a function to determine if t is an anagram of s.
//
//        For example,
//        s = "anagram", t = "nagaram", return true.
//        s = "rat", t = "car", return false.
//
//        Note:
//        You may assume the string contains only lowercase alphabets.

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created by chonchen on 2017/6/9.
 */
public class Solution {
    public boolean isAnagram(String s, String t) {
        char[] sChar = s.toCharArray();
        char[] tChar = t.toCharArray();

        Arrays.sort(sChar);
        Arrays.sort(tChar);

        return Arrays.equals(sChar, tChar);
    }

    public boolean isAnagram2(String s, String t) {
        if (s.length() != t.length()) {
            return  false;
        }

        int[] alphabets = new int[26];

        for (int i = 0; i < s.length(); i++) {
            alphabets[s.charAt(i) - 'a']++;
        }

        for (int i = 0; i < t.length(); i++) {
            alphabets[t.charAt(i) - 'a']--;
        }

        for (int item:
             alphabets) {
            if (item != 0) {
                return false;
            }
        }

        return true;
    }

    // 使用这种方法运行是最快的，toCharArrary 可能在编译的时候已经将其替换成数组了
    // 这样在实际运行过程中就是直接对数组操作
    // 第二种方法需要在运行时每次都调用 charAt 这可能会带来额外的开销
    public boolean isAnagram3(String s, String t) {

        int[] charsMap = new int['z'-'a'+1];

        for(char c: s.toCharArray()) {
            int pos = c - 'a';
            charsMap[pos]++;
        }

        for(char c: t.toCharArray()) {
            int pos = c - 'a';
            charsMap[pos]--;
        }

        for(int count: charsMap) {
            if(count != 0) {
                return false;
            }
        }

        return true;
    }
}

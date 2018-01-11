package com.company;

//Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string.
//If there are less than k characters left, reverse all of them.
//If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
//        Example:
//        Input: s = "abcdefg", k = 2
//        Output: "bacdfeg"
//        Input:  "1234567890abcd", k = 2
//        Output: "2134657809abdc"
//        Input :  "123", k = 2
//        Output:  "213"
//        Input: "abcdefg12345687959621", k = 5
//        Ouput: "edcbafg12378654959621"
//        Restrictions:
//        The string consists of lower English letters only.
//        Length of the given string and k will in the range [1, 10000]


/**
 * Created by chonchen on 2017/6/13.
 */
public class Solution {

    public String reverseStr2(String s, int k) {
        if (s.length() < 1) {
            return "";
        }

        int stringLen = s.length();
        char[] newString = s.toCharArray();

        if (stringLen < k) {
            // reverse all char
            for (int i = 0; i < stringLen; i++) {
                newString[i] = s.charAt(stringLen-i-1);
                //System.out.println(newString[i]);
            }
        } else if (stringLen >= k && stringLen < 2*k) {
            // reverse first k characters and left the other as original
            for (int i = 0; i < k; i++) {
                newString[i] = s.charAt(k - i - 1);
            }
        } else {
            // reverse the first k characters for every 2k characters counting from the start of the string
            // 这里还是没有想出解决办法
//            for (int i = 0; i < stringLen ; i += (2*k)) {
//                for (int j = 0; j < k; j++) {
//                    newString[i + j] = s.charAt(i + k - j - 1);
//                    System.out.println(newString[i+j]);
//                }
//            }

        }

        return String.valueOf(newString);
    }


    public String reverseStr(String s, int k) {

        char[] store = new char[s.length()];
        String ret = new String();

        if (s.length() <= k) {
            ret = s;
        } else if (s.length() >=k && s.length() <= (2*k)) {
            char[] sChar = s.toCharArray();
            int index = 0;
            for (; index < k; index++) {
                store[index] = sChar[k - index - 1];
            }
            for (; index < s.length(); index++) {
                store[index] = sChar[index];
            }
            ret = new String(store);
        } else {
            int group = (s.length() / k) + ((s.length() % k != 0) ? 1 : 0);
            int needReverseGroupNum = (group / 2) + ((group % 2 != 0) ? 1 : 0);
            int sLength = s.length();
            System.out.println("group:" + group + " loop:" + needReverseGroupNum);

//            int needReverseGroupNum = (s.length() / (2 * k)) + ((s.length() % (2 * k) != 0) ? 1 : 0);

            char[] sChar = s.toCharArray();
            int index = 0;
            for (int groupIndex = 0; groupIndex < needReverseGroupNum; groupIndex++) {
                int startSplit = groupIndex * (k * 2) + k;

                for (int i = 0; i < k && sLength > 0; i++) {
                    store[index++] = sChar[groupIndex * (k * 2) + k - i - 1];
//                    store[index++] = sChar[startSplit - i - 1];
                    sLength--;
                }
                for (int i = 0; i < k && sLength > 0; i++) {
                    store[index++] = sChar[groupIndex * (k * 2) + k + i];
//                    store[index++] = sChar[startSplit + i];
                    sLength--;
                }
                ret = new String(store);
                System.out.println(store);
            }
        }

        return ret;
    }
}

/* 
LeetCode
28. Implement strStr()
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1 */

public class Haystack {
    public Haystack() {
    }

    public int strStr3(String haystack, String needle) {
        return haystack.indexOf(needle);
    }

    public int strStr2(String haystack, String needle) {
        int lenHaystack = haystack.length();
        int lenNeedle = needle.length();

        if (lenNeedle == 0) {
            return 0;
        }

        if (lenNeedle > lenHaystack) {
            return -1;
        }

        for (int i = 0; i < lenHaystack; i++) {
            int j = 0;
            for (; j < lenNeedle; j++) {
                if (i+j >= lenHaystack) return -1;
                if (haystack.charAt(i+j) != needle.charAt(j)) break;
            }
            if (j == lenNeedle) {
                return i;
            }
        }

        return -1;
    }

    public int strStr(String haystack, String needle) {
        if (haystack == null || needle == null || haystack.length() < needle.length()) {
            return -1;
        } else if (haystack == needle || needle.length() == 0) {
            return 0;
        } else if (haystack.length() > 0 && needle.length() > 0) {
            int cursorHaystackIndex = 0;
            boolean found = false;
            for (int i = 0; i < haystack.length(); i++) {
                if (haystack.charAt(i) == needle.charAt(0)) {
                    cursorHaystackIndex = i;
    
                    int cursorNeedleIndex = 0;
                    for (int j = 0; j < needle.length(); j++) {
                        if (cursorHaystackIndex + j >= haystack.length()) return -1; // out of the arrary
                        if (haystack.charAt(cursorHaystackIndex + j) != needle.charAt(j)) break;
                        else cursorNeedleIndex = j;
                    }
    
                    if (cursorNeedleIndex + 1 == needle.length()) {
                        found = true;
                        break;
                    }
                }
            }
    
            if (found) return cursorHaystackIndex;
            else return -1;
        } else {
            return -1;
        }
    }

    public static void main(String[] args) {
        Haystack test = new Haystack();
        System.out.println("Result:" + test.strStr3(args[0], args[1]));
    }
}
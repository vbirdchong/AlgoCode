package com.company;

//Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.
//
//        You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.
//
//        Example 1:
//        Input:
//        ["Shogun", "Tapioca Express", "Burger King", "KFC"]
//        ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
//        Output: ["Shogun"]
//        Explanation: The only restaurant they both like is "Shogun".
//        Example 2:
//        Input:
//        ["Shogun", "Tapioca Express", "Burger King", "KFC"]
//        ["KFC", "Shogun", "Burger King"]
//        Output: ["Shogun"]
//        Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
//        Note:
//        The length of both lists will be in the range of [1, 1000].
//        The length of strings in both lists will be in the range of [1, 30].
//        The index is starting from 0 to the list length minus 1.
//        No duplicates in both lists.


//        Input:
//        ["Shogun","Tapioca Express","Burger King","KFC"]
//        ["KFC","Burger King","Tapioca Express","Shogun"]
//        Expected:
//        ["KFC","Burger King","Tapioca Express","Shogun"]
//

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by chonchen on 2017/6/9.
 */
public class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        int indexPlus = 0;
        int indexMinSum = 999 + 999;
        String[] bothLikeIndexStr = new String[Math.max(list1.length, list2.length)];
        int bothLikeIndex = 0;

        for (int i = 0; i < list1.length; i++) {
            for (int j = 0; j < list2.length; j++) {
                // 在 LeetCode 中，不可以直接判断字符串相等
                // 需要使用 equals 来判断
                //if (list1[i] == list2[j]) {
                if (list1[i].equals(list2[j])) {
                    indexPlus = i + j;
                    if (indexMinSum >= indexPlus) {
                        indexMinSum = indexPlus;
                        bothLikeIndexStr[bothLikeIndex++] = list2[j];
                        //System.out.print(list1[i]);
                    }
                }
            }
        }

        // 这里的处理是为了去除 bothLikeIndexStr 中的空对象，还有更好的处理的方法
        String[] ret = new String[bothLikeIndex];
        for (int i = 0; i < bothLikeIndex; i++) {
            ret[i] = bothLikeIndexStr[i];
        }
        return ret;
    }

    public String[] findRestaurant2(String[] list1, String[] list2) {
        List<String> result = null;
        Map<String, Integer> map1 = new HashMap<>();
        Map<String, Integer> map2 = new HashMap<>();
        int min = Integer.MAX_VALUE;

        for (int i = 0; i < list1.length; i++) {
            map1.put(list1[i], i);
        }

        for (int i = 0; i < list2.length; i++) {
            map2.put(list2[i], i);
        }

        for (int i = 0; i < list1.length; i++) {
            if (map2.containsKey(list1[i])) {
                int sum = map1.get(list1[i]) + map2.get(list1[i]);
                System.out.println("\nsum=" + sum + " min=" + min + " value=" + list1[i]);
                if (sum < min) {
                    min = sum;
                    result = new ArrayList<String>();
                    result.add(list1[i]);
                    System.out.println("result size:" + result.size() + " add value:" + list1[i]);
                }
                else if (sum == min) {
                    result.add(list1[i]);
                }
            }
        }

        String[] res = new String[result.size()];
        for (int i = 0; i < result.size(); i++) {
            res[i] = result.get(i);
        }

        return res;
    }
}

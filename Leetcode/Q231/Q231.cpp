
// 231. Power of Two
// Given an integer, write a function to determine if it is a power of two.

#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n > 0)
        {
        	return (n & (n-1)) == 0;
        }

        return false;
    }
};
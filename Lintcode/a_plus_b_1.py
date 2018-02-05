#! python3

# http://www.lintcode.com/zh-cn/problem/a-b-problem/#

import ctypes

class Solution:
    """
    @param a: An integer
    @param b: An integer
    @return: The sum of a and b
    """
    def aplusb(self, a, b):
        a = ctypes.c_int32(a).value
        b = ctypes.c_int32(b).value
        while(b != 0) :
            sum_val = ctypes.c_int32(a ^ b).value
            carry_val = ctypes.c_int32(a & b).value
            b = ctypes.c_int32(carry_val << 1).value
            a = sum_val
        return a

def main():
    solution = Solution()
    print(solution.aplusb(100,100))

if __name__ == '__main__':
    main()
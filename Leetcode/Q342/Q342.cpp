/*
342. Power of Four
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?

 */


#include <iostream>
#include <stdlib.h>



class Solution {
public:
    bool isPowerOfFour(int num) {

		const int Power[] = {(1 << 0), (1 << 2), (1 << 4), (1 << 6), (1 << 8),
								(1 << 10), (1 << 12), (1 << 14), (1 << 16),
								(1 << 18), (1 << 20), (1 << 22), (1 << 24),
								(1 << 26), (1 << 28), (1 << 30)};

		if (num <= 0)
		{
			return false;
		}
        else
        {
        	for (int i = 0; i < sizeof(Power)/sizeof(Power[0]); ++i)
        	{
        		//std::cout << "Power:" << i+1 << " = " << Power[i] << std::endl;
        		if ((num | Power[i]) == Power[i])
        		{
        			return true;
        		}
        	}
        	return false;
        }
    }

    bool isPowerOfFour2(int num) {
    	// 另一种解法，
    	// (n & (n - 1)) == 0 则表明是2的倍数
    	// n & 0x55555555 > 0 通过规律可以发现所有4的次数的数的奇数位都为1，那么只要判断它的位数上是否=1即可
    	return (n > 0) && (n & (n - 1) == 0) && (n & 0x55555555);
    }
};

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		int n = atoi(argv[1]);

		Solution sl;
		std::cout << "Ret: " << sl.isPowerOfFour(n) << std::endl;
	}
	return 0;
}

// 258. Add Digits

// Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

// For example:

// Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
    	// if (num < 10)
    	// {
    	// 	return num;
    	// }
    	// int sumValue = 0;
     //    while(num > 9){
     //    	sumValue += num	% 10;
     //    	num /= 10;
     //    }
     //    sumValue += num;
     //    return addDigits(sumValue);

    	// 另一种方法
		// 10^k % 9 = 1
		// a*10^k % 9 = a % 9 
		// Then let's use an example to help explain.

		// Say a number x = 23456

		// x = 2* 10000 + 3 * 1000 + 4 * 100 + 5 * 10 + 6

		// 2 * 10000 % 9 = 2 % 9

		// 3 * 1000 % 9 = 3 % 9

		// 4 * 100 % 9 = 4 % 9

		// 5 * 10 % 9 = 5 % 9

		// Then x % 9 = ( 2+ 3 + 4 + 5 + 6) % 9, note that x = 2* 10000 + 3 * 1000 + 4 * 100 + 5 * 10 + 6

		// So we have 23456 % 9 = (2 + 3 + 4 + 5 + 6) % 9
    	if (num == 0){
    		return 0;
    	}
    	if (num % 9 == 0){
    		return 9;
    	}
    	else{
    		return num % 9;
    	}
    }
};

int main(/*int argc, char const *argv[]*/)
{
	Solution sl;
	cout << sl.addDigits(123);
	return 0;
}

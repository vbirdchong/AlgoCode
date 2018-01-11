
/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, 
replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

// 注意下面的2表示的是平方
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
 */


#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0 || n == 4){
        	return false;
        }
        else if (1 == n) {
        	return true;
        }
        else{
        	int sum = 0;
        	while(n > 0){
        		int remainder = n % 10;
        		sum += pow(double(remainder), 2.0);
        		n = (n / 10);
        	}
        	return isHappy(sum);
        }
    }
};

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		int n = atoi(argv[1]);
		cout << n << endl;

		Solution sl;
		cout << "ret: " << sl.isHappy(n) << endl;
	}
	return 0;
}
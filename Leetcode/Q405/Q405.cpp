
// 405. Convert a Number to Hexadecimal

// Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

// Note:

// All letters in hexadecimal (a-f) must be in lowercase.
// The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
// The given number is guaranteed to fit within the range of a 32-bit signed integer.
// You must not use any method provided by the library which converts/formats the number to hex directly.

// Example 1:

// Input:
// 26

// Output:
// "1a"
// Example 2:

// Input:
// -1

// Output:
// "ffffffff"

#include <iostream>
#include <string>

using namespace std;

const char strHex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
						'a', 'b', 'c', 'd', 'e', 'f'};

class Solution {
public:
    string toHex(int num) {
    	string ret = "";
    	
    	if (num != 0)
    	{
	       	for (int i = 0; i < 8; ++i)
	       	{
	       		if ((num & 0xffffffff) != 0){
		       		int hexV = num & 0xf;
		       		cout << hex << hexV << '\n';
		       		num = num >> 4;
	       			ret.insert(0, 1, strHex[hexV]);
	       		}
	       	}
    	}
    	else{
    		return "0";
    	}
        return ret;
    }
};

int main()
{
	Solution sl;
	cout << sl.toHex(-0);
	return 0;
}
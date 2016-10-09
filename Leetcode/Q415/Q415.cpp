// Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

// Note:

// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int minLen = num1.length();
		string bigNumHead;
		// 如果两个字符串长度不同，那么将长字串截取成和短字串一样长，并把多余的高位放在另一个字串中
        if (num1.length() > num2.length())
        {
        	minLen = num2.length();
        	bigNumHead.insert(0, num1, 0, num1.length() - minLen);
        	num1.erase(0, bigNumHead.length());
        }
        else if (num2.length() > num1.length())
        {
        	minLen = num1.length();
        	bigNumHead.insert(0, num2, 0, num2.length() - minLen);
        	num2.erase(0, bigNumHead.length());
        	//cout << "bigNumHead" << bigNumHead << ',' << num2 << endl;
        }

        string ret;
        int carry = 0;

        //cout << num1 << ',' << num2 << endl;
		// 对于截取后的字串中的数字进行相加，并考虑进位
        for (int i = minLen - 1; i >= 0; --i)
        {
        	int value = (num1[i] - '0') + (num2[i] - '0') + carry;
        	// cout << value <<"," << num1[i] << ',' << num2[i] << endl;
        	if (value > 9)
        	{
        		value = value - 10;
        		carry = 1;
        	}
        	else
        	{
        		carry = 0;
        	}
        	char charValue = value + '0';
        	// cout << charValue << ',' << carry << endl;
        	ret.insert(0, 1, charValue);
        }

        if (carry == 0)
        {
        	ret = bigNumHead + ret;
        }
        else // 有进位的情况
        {
			// 如果传入的两个字串的长度是一样的，那么直接将进位添加进去
        	if (bigNumHead.length() == 0)
        	{
        		ret.insert(0, 1, carry + '0');
        	}
        	else // 否则这里要考虑之前另存的高位的数字，并进行进位的处理
        	{
	        	for (int i = bigNumHead.length() - 1;  i >= 0 ; --i)
		        {
		        	int value = bigNumHead[i] - '0' + carry;
		        	
		        	if (value > 9)
		        	{
		        		value = value - 10;
		        		carry = 1;
		        	}
		        	else
		        	{
		        		carry = 0;
		        	}
		        	char charValue = value + '0';
		        	ret.insert(0, 1, charValue);
		        }
		        if (carry != 0)
		        {
		        	ret.insert(0, 1, carry + '0');
		        }
        	}
	        
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution sl;
	cout << "Retuen value:" << sl.addStrings(argv[1], argv[2]) << endl;
	return 0;
}

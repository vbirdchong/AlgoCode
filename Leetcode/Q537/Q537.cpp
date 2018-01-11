// 537. Complex Number Multiplication

// Given two strings representing two complex numbers.

// You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

// Example 1:
// Input: "1+1i", "1+1i"
// Output: "0+2i"
// Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
// Example 2:
// Input: "1+-1i", "1+-1i"
// Output: "0+-2i"
// Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
// Note:

// The input strings will not have extra blank.
// The input strings will be given in the form of a+bi, 
// where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
// 

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int aReal = 0, aImag = 0, bReal = 0, bImag = 0;
        getRealImagPart(a, aReal, aImag);
        getRealImagPart(b, bReal, bImag);
        // cout << aReal << ',' << aImag << endl;
        // cout << bReal << ',' << bImag << endl;

        int newReal = aReal * bReal + (aImag * bImag * (-1));
        int newImag = aImag * bReal + bImag * aReal;
        // cout << "new:" << newReal << ',' << newImag << endl;

        stringstream ret;
        ret << newReal << "+" << newImag << "i";
        // cout << ret.str();
        return ret.str();
    }

    void getRealImagPart(string a, int& real, int& imag){
        size_t aPlusSign = a.find('+');
        string aStrReal(a, 0, aPlusSign);
        string aStrImag(a, aPlusSign + 1, a.size() - aPlusSign - 2);
        real = atoi(aStrReal.c_str());
        imag = atoi(aStrImag.c_str());
    }
};


int main(void)
{
    Solution sol;
    string a = "1+2i";
    string b = "3+4i";

    cout << sol.complexNumberMultiply(a, b);
    return 0;
}
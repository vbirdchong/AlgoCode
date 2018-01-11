
// 461. Hamming Distance

// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

// Given two integers x and y, calculate the Hamming distance.

// Note:
// 0 ≤ x, y < 231.

// Example:

// Input: x = 1, y = 4

// Output: 2

// Explanation:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑

// The above arrows point to positions where the corresponding bits are different.
// 
// 

#include <iostream>
#include <bitset>


using namespace std;


class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorval = x ^ y;
        bitset<32> bitVal(xorval);
        return bitVal.count();
    }
};


int main()
{
    Solution sol;
    cout << sol.hammingDistance(1, 4);
    return 0;
}
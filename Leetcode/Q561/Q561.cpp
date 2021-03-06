// 561. Array Partition I

// Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

// Example 1:
// Input: [1,4,3,2]

// Output: 4
// Explanation: n is 2, and the maximum sum of pairs is 4.
// Note:
// n is a positive integer, which is in the range of [1, 10000].
// All the integers in the array will be in the range of [-10000, 10000].
// 
// 

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (vector<int>::iterator i = nums.begin(); i != nums.end(); )
        {
            sum += *i;
            i += 2;
        }

        return sum;
    }

    void printVector(vector<int> nums){
        for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
        {
            std::cout << *i << '\n';
        }
    }
};

int main(void)
{
    int nums[] = {1,4,3,2,6,5};
    vector<int> vNums(nums, nums + (sizeof(nums)/sizeof(int)));

    Solution sol;
    cout << "ret=" << sol.arrayPairSum(vNums) << endl;
    // sol.printVector(vNums);

    return 0;
}
// 169. Majority Element

// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.


#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        return nums[(nums.size() / 2)];
    }
};

int main()
{
	int testNum[] = {1,3,2,1,5,2,1,6,7,3,1,1,1,3,1};
	std::vector<int> nums(testNum, testNum + (sizeof(testNum)/sizeof(int)));
	cout << (sizeof(testNum)/sizeof(int)) << endl;
	Solution sl;
	cout << sl.majorityElement(nums);

	return 0;
}
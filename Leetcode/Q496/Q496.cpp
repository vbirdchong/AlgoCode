// 496. Next Greater Element I

// You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

// The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

// Example 1:
// Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
// Output: [-1,3,-1]
// Explanation:
//     For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
//     For number 1 in the first array, the next greater number for it in the second array is 3.
//     For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
// Example 2:
// Input: nums1 = [2,4], nums2 = [1,2,3,4].
// Output: [3,-1]
// Explanation:
//     For number 2 in the first array, the next greater number for it in the second array is 3.
//     For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
// Note:
// All elements in nums1 and nums2 are unique.
// The length of both nums1 and nums2 would not exceed 1000.
// 


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        std::vector<int> result;

        for (int i = 0; i < findNums.size(); ++i)
        {
            int equalValIndex = -1;
            bool findVal = false;
            for (int j = 0; j < nums.size(); ++j)
            {
                if (findNums[i] == nums[j])
                {
                    cout << "find the equal value, index:" << i << ',' << findNums[i] << ',' << j << endl;
                    equalValIndex = j;
                }
                else if ((equalValIndex != -1) && (equalValIndex < j) && (findNums[i] < nums[j]))
                {
                    cout << equalValIndex << ',' << i << ',' << j << ',' << findNums[i] << ',' << nums[j] << endl;
                    result.push_back(nums[j]);
                    findVal = true;
                    break;
                }
            }

            if (!findVal)
            {
                result.push_back(-1);
            }
        }

        return result;
    }


    vector<int> nextGreaterElement2(vector<int>& findNums, vector<int>& nums){
        std::vector<int> result;

        for (int i = 0; i < findNums.size(); ++i)
        {
            bool findVal = false;
            int j = 0;
            for (j = 0; j < nums.size(); ++j)
            {
                if (findNums[i] == nums[j])
                {
                    break;
                }
            }

            for (int k = j + 1; k < nums.size(); ++k)
            {
                if (nums[k] > findNums[i])
                {
                    findVal = true;
                    result.push_back(nums[k]);
                    break;
                }
            }

            if (!findVal)
            {
                result.push_back(-1);
            }
        }

        return result;
    }


    void pirntResult(std::vector<int> result){
        cout << "Result: " << '\n';
        for (std::vector<int>::iterator i = result.begin(); i != result.end(); ++i)
        {
            cout << *i << endl;
        }
    }
};


int main()
{
    Solution solution;

    std::vector<int> nums1;
    std::vector<int> nums2;

    nums1.push_back(4);
    nums1.push_back(1);
    nums1.push_back(2);

    nums2.push_back(1);
    nums2.push_back(3);
    nums2.push_back(4);
    nums2.push_back(2);

    std::vector<int> result = solution.nextGreaterElement2(nums1, nums2);
    solution.pirntResult(result);

    return 0;
}
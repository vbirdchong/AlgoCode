
// 448. Find All Numbers Disappeared in an Array

// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

// Find all the elements of [1, n] inclusive that do not appear in this array.

// Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

// Example:

// Input:
// [4,3,2,7,8,2,3,1]

// Output:
// [5,6]
// 
// 


#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::vector<int> valueMark(nums.size(), 0);
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            valueMark[nums[i] - 1] = 1;
        }

        std::vector<int> res;
        for (int i = 0; i < valueMark.size(); ++i)
        {
            if (valueMark[i] == 0)
            {
                res.push_back(i + 1);
            }
        }

        return res;
    }


    void printResult(vector<int> v){
        cout << "Print result:" << endl;
        for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
        {
            cout << "Result: " << *i << endl;
        }
    }
};


int main()
{
    int myints[] = {4,3,2,7,8,2,3,1};
    std::vector<int> myvector (myints, myints+8);

    Solution solution;
    std::vector<int> res;
    res = solution.findDisappearedNumbers(myvector);

    solution.printResult(res);

    return 0;
}

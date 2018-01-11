
/*
27. Remove Element

Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int findValIdx = 0;
        for(vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++, findValIdx++){
            if(val == *itr){
              nums.erase(nums.begin() + findValIdx);
              itr--;
              findValIdx--;
            }
        }

        return nums.size();
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    Solution sol;
    cout << "len:" << sol.removeElement(nums, 3) << '\n';
    for(vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++ ){
        cout << *itr << '\n';
    }

    return 0;
}


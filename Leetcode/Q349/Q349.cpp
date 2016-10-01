
// 349. Intersection of Two Arrays

// Given two arrays, write a function to compute their intersection.

// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

// Note:
// Each element in the result must be unique.
// The result can be in any order.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/*
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> ret;

    	for (int i = 0; i < nums1.size(); i++){
    		int value = nums1[i];
    		for (int i = 0; i < nums2.size(); ++i){
    			if (value == nums2[i]){
    				if(!isAlreadyExit(ret, value)){
    					ret.push_back(value);
    				}
    			}
    		}
    	}   
    	return ret;
    }

    bool isAlreadyExit(std::vector<int>& v, int valueCheck){
    	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i){
    		if ((*i) == valueCheck){
    			return true;
    		}
    	}
    	return false;
    }
    */

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    	sort(nums1.begin(), nums1.end());
    	sort(nums2.begin(), nums2.end());

    	if (nums1.size() > nums2.size())
    	{
    		/* code */
    	}
    }
};

int main()
{
	std::vector<int> nums1, nums2;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(2);
	nums1.push_back(1);
	nums1.push_back(3);

	nums2.push_back(2);
	nums2.push_back(2);
	nums2.push_back(3);

	Solution sl;
	std::vector<int> ret;
	ret = sl.intersection(nums1, nums2);
	for (std::vector<int>::iterator i = ret.begin(); i != ret.end(); ++i)
	{
		cout << *i << endl;	
	}
	
	return 0;
}
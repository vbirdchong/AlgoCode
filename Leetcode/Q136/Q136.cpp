// 136. Single Number
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		// 这种方法太耗时
        // for(int i = 0; i <= nums.size() - 1; i++){
			// int firstV = nums[i];
			// bool backwardFind = false;
			// bool forwardFind = false;
			
			// // 往后查找
			// for(int j = i+1; j < nums.size(); j++){
				// // 找到了重复的值
				// if (firstV == nums[j]){
					// backwardFind = true;
					// continue;
				// }
			// }
			
			// // 往前查找
			// if(i > 0){
				// for(int j = 0; j < i; j++){
					// if(firstV == nums[j]){
						// forwardFind = true;
						// continue;
					// }
				// }
			// }
			
			// // 前后都没有找到
			// if(!backwardFind && !forwardFind){
				// return nums[i];
			// }
		// }
		// return 0;
		
		// 使用库函数
		return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
		
    }
	
	// 网友NB算法
	// for(int i = 0; i < nums.size(); i++){
		// nums[0] ^= nums[i];
	// }
	// return nums[0];
};

int main(){
	vector <int> num;
	num.push_back(23);
	num.push_back(3);
	num.push_back(3);
	
	Solution sl;

	cout << sl.singleNumber(num);
}
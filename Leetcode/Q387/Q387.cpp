
// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

// Examples:

// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.


#include <iostream>
#include <string>

using namespace std;

class Solution{
public: 
    int firstUniqChar(string s){
    	// 记录字符在字符串中的下标位置
		int charIndex[256] = {0};				
		// 每个字符出现的次数
		int charCount[256] = {0};

		// 数组下标对应的是每个字符，数组中的内容表示的字符在字符串中的下标，如果有重复的字符则会更新
		// 那么只要在这个数组中找到字符下标最小的那个就可以了
		for (int i = 0; i < s.length(); ++i){
			charIndex[(int)(s[i])] = i;	
			charCount[(int)(s[i])]++;
		}

		// 只查找出现一次的情况，并找其中最小的下标值	
		int minIndex = 65535;
		for (int i = 0; i < 256; i++){
			if (charCount[i] == 1){
				if ( minIndex > charIndex[i]){
					minIndex = charIndex[i];
				}
			}
		}
		
		if (minIndex != 65535){
			return minIndex;	
		}
		
		return -1;
    }
};


int main(int argc, char *argv[]){
	Solution sl;
	//	string tmp = "loveleetcode";
	
	string tmp = argv[1];
	cout << "index:" << sl.firstUniqChar(tmp) << endl;
}


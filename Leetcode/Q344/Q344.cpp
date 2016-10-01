
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        string ret;
		for(int i = 0; i < s.length(); ++i){
			ret += s[s.length() - i - 1];
		}
		
		return ret;
    }
};

int main(){
	Solution solu;
	
	cout << "val:" << solu.reverseString("hello world");
}
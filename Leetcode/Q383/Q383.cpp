
// 383. Ransom Note

// Given  an  arbitrary  ransom  note  string  and  another  string  containing  letters from  all  the  magazines,  write  a  function  that  will  return  true  if  the  ransom   note  can  be  constructed  from  the  magazines ;  otherwise,  it  will  return  false.   

// Each  letter  in  the  magazine  string  can  only  be  used  once  in  your  ransom  note.

// Note:
// You may assume that both strings contain only lowercase letters.

// canConstruct("a", "b") -> false
// canConstruct("aa", "ab") -> false
// canConstruct("aa", "aab") -> true

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool ret = true;
        for (int i = 0; i < ransomNote.length(); ++i)
        {
        	size_t found = magazine.find(ransomNote[i]);
        	if (found != string::npos)
        	{
        		magazine.erase(found, 1);
        	}
        	else{
        		ret = false;
        		break;
        	}
        }
        return ret;
    }
};

int main()
{
	Solution sl;
	string s = "fffbfg";
	string t = "effjfggbffjdgbjjhhdegh";

	cout << sl.canConstruct(s, t) << endl;
	return 0;
}
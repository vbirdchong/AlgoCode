
// 520. Detect Capital

// Given a word, you need to judge whether the usage of capitals in it is right or not.

// We define the usage of capitals in a word to be right when one of the following cases holds:

// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital if it has more than one letter, like "Google".
// Otherwise, we define that this word doesn't use capitals in a right way.
// 
// Example 1:
// Input: "USA"
// Output: True
// Example 2:
// Input: "FlaG"
// Output: False
// 

#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool detectCapitalUse(string word) {
        int judge = 0;
        for (int i = 0; i < word.size(); ++i)
        {
            if (word[i]<='Z' && word[i] >= 'A')
            {
                ++judge;
            }
            else if (word[i] <= 'z' && word[i] >= 'a')
            {
                --judge;
            }
        }

        if ( judge == word.size()
            || (judge + word.size() == 0))
        {
            return true;
        }
        else if (((judge - 2 + word.size()) == 0) 
                    && (word[0] <= 'Z' && word[0] >= 'A'))
        {
            return true;
        }

        return false;
    }
};


int main(/*int argc, char const *argv[]*/)
{
    string s1 = "USA";
    string s2 = "usa";
    string s3 = "Google";
    string s4 = "GloGG";

    Solution sol;
    cout << s1 << ':' << sol.detectCapitalUse(s1) << '\n';
    cout << s2 << ':' << sol.detectCapitalUse(s2) << '\n';
    cout << s3 << ':' << sol.detectCapitalUse(s3) << '\n';
    cout << s4 << ':' << sol.detectCapitalUse(s4) << '\n';

    return 0;
}
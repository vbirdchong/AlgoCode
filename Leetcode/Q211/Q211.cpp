
#include <iostream>
#include <vector>

using namespace std;

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        m_word.push_back(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
		
		for(int j = 0; j < m_word.size(); j++){
			// 要查找的字串长度大于原始字串
			if(m_word[j].length() < word.length()){
				continue;
			}
			int verification_count = 0;
			
			for(int i = 0; i < word.length(); i++ ){
				if(word[i] != '.'){
					if(word[i] == m_word[j][i]){
						verification_count++;
					}
				}
				else{
					verification_count++;
				}
			}
			
			if(verification_count == word.length()){
				return true;
			}
		}
		return false;
    }
	
private:
	//string m_word;
	vector <string> m_word;
};

int main()
{
	// Your WordDictionary object will be instantiated and called as such:
	WordDictionary wordDictionary;
	wordDictionary.addWord("bad");
	wordDictionary.addWord("dad");
	wordDictionary.addWord("mad");
	cout << wordDictionary.search("pad") << endl;
	cout << wordDictionary.search("bad") << endl;
	cout << wordDictionary.search(".ad") << endl;
	cout << wordDictionary.search("b..") << endl;
	
	// wordDictionary.addWord("a");
	// wordDictionary.addWord("a");
	// cout << wordDictionary.search(".") << endl;
	// cout << wordDictionary.search("a") << endl;
	// cout << wordDictionary.search("aa") << endl;
	// cout << wordDictionary.search("a") << endl;
	// cout << wordDictionary.search(".a") << endl;
	// cout << wordDictionary.search("a.") << endl;
	return 0;
	
}
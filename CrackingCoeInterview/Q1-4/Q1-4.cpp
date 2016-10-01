#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

/*
	判断两个字符串是不是变位词， abcd, addc为变位词
*/
bool isAnagrams1(string s, string t)
{
	if (s == "" || t == "")
	{
		return false;
	}

	if (s.length() != t.length())
	{
		return false;
	}

	sort(&s[0], &s[0]+s.length());
	sort(&t[0], &t[0]+t.length());
	if (s == t)
	{
		return true; 
	}
	return false;
}

bool isAnagrams2(string s, string t)
{
	if (s == "" || t == "")
	{
		return false; 
	}

	if (s.length() != t.length())
	{
		return false; 
	}

	int len = s.length();
	int c[256] = {0};
	memset(c, 0x0, sizeof(c));
	
	for (int i = 0; i < len; ++i)
	{
		++c[int(s[i])];
		--c[int(t[i])];
	}

	for (int i = 0; i < 256; ++i)
	{
		if (c[i] != 0)
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	string s = "abcd", t = "adbc";

	cout << "String " << s << "," << t << " is anagram1: " << isAnagrams1(s, t) << endl;
	cout << "String " << s << "," << t << " is anagram2: " << isAnagrams2(s, t) << endl;

	return 0;
}
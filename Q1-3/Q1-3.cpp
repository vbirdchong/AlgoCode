
#include <iostream>
#include <cstring>

using namespace std;

void removeDeplicate1(char s[])
{
	int len = strlen(s);
	int p = 0;
	if (len < 2)
	{
		return;
	}

	for (int i = 0; i < len; ++i)
	{
		if (s[i] != '\0')
		{
			s[p++] = s[i];

			for (int j = i+1; j < len; ++j)
			{
				if (s[j] == s[i])
				{
					s[j] = '\0';
				}
			}
		}
	}
	s[p] = '\0';
}


void removeDeplicate2(char s[])
{
	int len = strlen(s);
	if (len < 2)
	{
		return;
	}
	int p = 0;
	bool c[256] = {0};
	memset(c, 0, sizeof(c));

	for (int i = 0; i < len; ++i)
	{
		if (c[s[i]] != true)
		{
			s[p++] = s[i];
			c[s[i]] = true;
		}
	}
	s[p] = '\0';
}


void removeDeplicate3(char s[])
{
	int len = strlen(s);
	if (len < 2)
	{
		return;
	}
	int p = 0;
	int index_bitmap = 0;

	for (int i = 0; i < len; ++i)
	{
		// 字符串的范围是'a-z', 26个小写字母
		int v = (int)(s[i] - 'a');
		if ((index_bitmap & (1 << v)) == 0)
		{
			s[p++] = s[i];
			index_bitmap |= (1 << v);
		}
	}
	s[p] = '\0';
}


string removeDeplicate4(string s)
{
	int len = s.length();
	if (len < 2)
	{
		return s;
	}
	string ret_str = "";

	for (int i = 0; i < len; ++i)
	{
		if (s[i] != '\0')
		{
			ret_str += s[i];
			for (int j = i+1; j < len; ++j)
			{
				if (s[j] == s[i])
				{
					s[j] = '\0';
				}
			}
		}
	}

	return ret_str;
}

string removeDeplicate5(string s)
{
	int len = s.length();
	if (len < 2)
	{
		return s;
	}

	string ret_str = "";
	bool c[256] = {0};
	memset(c, 0, sizeof(c));

	for (int i = 0; i < len; ++i)
	{
		if (c[s[i]] == false)
		{
			ret_str += s[i];
			c[s[i]] = true;
		}
	}

	return ret_str;
}

string removeDeplicate6(string s)
{
	int len = s.length();
	if (len < 2)
	{
		return s;
	}

	string ret_str = "";
	int index_bitmap = 0;

	for (int i = 0; i < len; ++i)
	{
		int v = (int)(s[i] - 'a');
		if ((index_bitmap & (1 << v)) == 0)
		{
			ret_str += s[i];
			index_bitmap |= (1 << v);
		}		
	}

	return ret_str;
}


int main(int argc, char const *argv[])
{
	char s1[] = "abcde";
	char s2[] = "aaabbb";
	char s3[] = "";
	char s4[] = "abababc";
	char s5[] = "ccccc";

	// removeDeplicate1(s1);
	// removeDeplicate1(s2);
	// removeDeplicate1(s3);
	// removeDeplicate1(s4);
	// removeDeplicate1(s5);

	// removeDeplicate2(s1);
	// removeDeplicate2(s2);
	// removeDeplicate2(s3);
	// removeDeplicate2(s4);
	// removeDeplicate2(s5);	

	removeDeplicate3(s1);
	removeDeplicate3(s2);
	removeDeplicate3(s3);
	removeDeplicate3(s4);
	removeDeplicate3(s5);	

	cout << "1 change to: "<< endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;

	string s11 = "abcde";
	string s22 = "aaabbb";
	string s33 = "";
	string s44 = "abababc";
	string s55 = "ccccc";

	// removeDeplicate4(s11);
	// removeDeplicate4(s22);
	// removeDeplicate4(s33);
	// removeDeplicate4(s44);
	// removeDeplicate4(s55);

	// removeDeplicate5(s11);
	// removeDeplicate5(s22);
	// removeDeplicate5(s33);
	// removeDeplicate5(s44);
	// removeDeplicate5(s55);	

	removeDeplicate6(s11);
	removeDeplicate6(s22);
	removeDeplicate6(s33);
	removeDeplicate6(s44);
	removeDeplicate6(s55);	

	cout << "2 change to: "<< endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;

	return 0;
}
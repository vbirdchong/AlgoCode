
#include <cstring>
#include <iostream>
using namespace std;

void removeDuplicate1(char s[])
{
	int len = strlen(s);

	if (len < 2)
	{
		return;
	}

	int p = 0;
	for (int i = 0; i < len; ++i)
	{
		if (s[i] != '\0')
		{
			// 使用下标'p'来指示新字符串的下标
			s[p] = s[i];
			p++;

			// 从i+1开始，直到字符串最后，如果有相等的字符串，则全部置成'\0'
			for (int j = i+1; j < len; ++j)
			{
				if (s[j] == s[i])
				{
					s[j] = '\0';
				}
			}
		}
	}
	// 在新字符串之后添加结束符
	s[p] = '\0';
}

// 如果允许开辟一个数组
void removeDuplicate2(char s[])
{
	int len = strlen(s);
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


// 如果字符的大小范围是'a - z', 只有26个小写字符
void removeDuplicate3(char s[])
{
	int len = strlen(s);
	int p = 0;
	int index_bitmap = 0;

	for (int i = 0; i < len; ++i)
	{
		int v = (int)(s[i] - 'a');
		if ((index_bitmap & (1 << v)) == 0)
		{
			s[p++] = s[i];
			index_bitmap |= (1 << v);
		}
	}
	s[p] = '\0';
}


int main(int argc, char const *argv[])
{
	char s1[] = {"abcde"};
    char s2[] = {"aaabbb"};
    // char s3[] = {""};
    char s4[] = {"abababc"};
    char s5[] = {"ccccc"};
	cout << "s1: " << s1 << endl;

	// removeDuplicate1(s1);
	// removeDuplicate1(s2);
	// removeDuplicate1(s3);
	// removeDuplicate1(s4);
	// removeDuplicate1(s5);

	// removeDuplicate2(s1);
	// removeDuplicate2(s2);
	// removeDuplicate2(s3);
	// removeDuplicate2(s4);
	// removeDuplicate2(s5);

	removeDuplicate3(s1);
	removeDuplicate3(s2);
	removeDuplicate3(s4);
	removeDuplicate3(s5);

	cout << "change to: " << s1 << endl;
	cout << "change to: " << s2 << endl;
	// cout << "change to: " << s3 << endl;
	cout << "change to: " << s4 << endl;
	cout << "change to: " << s5 << endl;

	return 0;
}
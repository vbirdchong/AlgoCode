
#include <cstring>
#include <iostream>

using namespace std;

int swap_char(char * str, int len)
{
	for (int i = 0; i < len/2; ++i)
	{
		char a = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = a;
	}

	return 0;
}

void swap(char &a, char &b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}

void reverse(char *s)
{
	if (!s)
		return;

	char *p = s, *q = s;
	// 将指针一直往后偏移，直到结束符
	while(*q)
	{
		++q;
	}
	// 将位置再往前移一格，在非结束符处
	--q;

	while(p < q)
	{
		swap(*p++, *q--);
	}
}


int main(int argc, char const *argv[])
{
	char test[] = {"1234567890"};
	
	reverse(test);
	// swap_char(test, strlen(test));
	cout << test << endl;

	return 0;
}
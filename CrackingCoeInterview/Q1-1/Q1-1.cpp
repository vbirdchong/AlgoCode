
#include <cstring>
#include <iostream>

using namespace std;

bool is_unique(string s)
{
	char c[256];
	memset(c, 0, sizeof(c));

	int len = s.length();
	for (int i = 0; i < len; ++i)
	{
		int index = (int)(s[i]);
		if (c[index])
		{
			return false;
		}

		c[index] = true;
	}

	return true;
}

bool is_unique_bitmap(string s)
{
	int bit_value[8];
	memset(bit_value, 0, sizeof(bit_value));

	int len = s.length();
	for (int i = 0; i < len; ++i)
	{
		int index = (int)(s[i]);
		int bit_idx = index / 32, shift = index % 32;

		if (bit_value[bit_idx] & (1 << shift))
		{
			return false;
		}

		bit_value[bit_idx] |= (1 << shift);
	}

	return true;
}



int main()
{
	string s1 = "hi world";
	string s2 = "fsflskajlkjjjdskfje";

	cout << s1 << " is unique: " << is_unique_bitmap(s1) << endl;
	cout << s2 << " is unique: " << is_unique_bitmap(s2) << endl;
	return 0;
}
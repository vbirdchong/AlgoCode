#include <iostream>
#include <cstring>

using namespace std;

char* replace(char* c)
{
	if (NULL == c)
	{
		return NULL;
	}

	int len = strlen(c);
	if (0 == len)
	{
		return NULL;
	}

	int space_cnt = 0;
	for (int i = 0; i < len; ++i)
	{
		if (c[i] == ' ')
		{
			++space_cnt;
		}
	}

	char* ret_c = new char[len + 2*space_cnt + 1];

	int index = 0;
	for (int i = 0; i < len; ++i)
	{

		if (c[i] == ' ')
		{
			ret_c[index] = '%';
			ret_c[index+1] = '2';
			ret_c[index+2] = '0';
			index += 3;
		}
		else
		{
			ret_c[index] = c[i];
			++index;
		}
	}

	ret_c[index] = '\0';

	return ret_c;
}

int main(int argc, char const *argv[])
{
	// this is a hello world 
	// this%20is%20a%20hello%20world

	char c[256] = "this is a hello world";
	char * ret = NULL;
	ret = replace(c);
	cout << ret << endl;
	delete ret;
	
	return 0;
}
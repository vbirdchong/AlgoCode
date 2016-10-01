#include <iostream>
#include <cstring>

using namespace std;

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}


void transpose(int a[][4], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			swap(a[i][j], a[j][i]);
		}
	}

	for (int i = 0; i < n/2; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			swap(a[i][j], a[n-i-1][j]);
		}
	}

}

int main(int argc, char const *argv[])
{
	int a[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10,11,12},
		{13,14,15,16}
	};

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}

	transpose(a, 4);

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}
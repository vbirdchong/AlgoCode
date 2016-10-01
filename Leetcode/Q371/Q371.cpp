// 371. Sum of Two Integers
// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

// Example:
// Given a = 1 and b = 2, return 3.

#include <iostream>

using namespace std;

class Solution
{
public:
	//Solution();
	//~Solution();
	
public:
	int getSum(int a, int b){
	使用加法器的方法实现
		if (a == 0)
		{
			return b;
		}
		else if (b == 0)
		{
			return a;
		}

		while(b != 0){
			int tmp = a ^ b;
			b = (a & b) << 1;
			a = tmp;
		}
		return a;

		// 使用这种方法会有编译问题，但也是很另类的解题方法
		// 将a的值作为c的地址，比如 a=10, 那么c地址就是0xA ，但这个地址是非法的，不能进行访问
		// 在c地址的基础上进行b的偏移，其实就是将a,b 进行相加,由于相加后还是一个非法地址，使用& 将*进行消除，这样返回后就是相加的值
		// char* c = (char*)a;
		// return (int)&(*(c+b));
	}
};

int main()
{
	Solution sl;
	cout << sl.getSum(55, 100);
	return 0;
}
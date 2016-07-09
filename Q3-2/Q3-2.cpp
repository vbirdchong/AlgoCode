/*
Subject:
How would you design a stack which, in addition to push and pop, 
also has a function min which returns the minimum element? Push, pop and min should all operate in O(1) time.

*/


#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#ifndef MAX_INT
#define MAX_INT (~(1 << 31))
#endif

class stack
{
typedef struct node
{
	int min;
	int val;
}node;

public:
	stack(int size = 10){
		m_buf = new node[size];
		memset(m_buf, 0x0, sizeof(node)*size);
		m_buf[0].min = MAX_INT;
		m_buf[0].val = 0;
		m_cur = 0;
	};


	~stack(){
		if (m_buf)
		{
			delete [] m_buf;
		}
	};
	
	void push(int val){
		m_buf[++m_cur].val = val;

		if (val < m_buf[m_cur - 1].min){
			m_buf[m_cur].min = val;
		}
		else{
			m_buf[m_cur].min = m_buf[m_cur - 1].min;
		}
	}

	int pop(){
		int ret = m_buf[m_cur].val;
		m_cur--;
		return ret;
	}

	int min(){
		return m_buf[m_cur].min;
	}


private:
	node *m_buf;
	int m_cur;
};


// method 2
// create two stacks:s1, s2. s1 save the all push val, s2 to save the stage samllest value 

class CStackBase
{
public:
	CStackBase(int size = 1000){
		buf = new int[size];
		cur = -1;
	};

	~CStackBase(){
		if(buf)
			delete [] buf;
	};

	void push(int val){
		buf[++cur] = val;
	}

	void pop(){
		--cur;
	}

	int top(){
		return buf[cur];
	}

	bool empty(){
		return cur == -1;
	}

private:
	int *buf;
	int cur;
};


class CStackMin
{
public:
	CStackMin(int size=1000){
		s1 = CStackBase(size);
		s2 = CStackBase(size);
	};

	~CStackMin(){
	};

	void push(int val){
		s1.push(val);
		if (val < min())
		{
			s2.push(val);
		}

	}

	void pop(){
		if (s1.top() == min())
		{
			s2.pop();
		}
		s1.pop();
	}

	int top(){
		return s1.top();
	}

	bool empty(){
		return s1.empty();
	}

	int min(){
		if (s2.empty()){
			return MAX_INT;
		}
		else{
			return s2.top();
		}

	}
	
private:
	CStackBase s1, s2;
};

int main(int argc, char const *argv[])
{
	// stack t = stack(10);
	CStackMin t = CStackMin(10);

	for (int i = 0; i < 10; ++i)
	{
		int rd = rand();
		cout << "rand the value: " << rd << endl;
		t.push(rd);
	}

	cout << "t.min=" << t.min() << endl;
	// cout << "t.pop=" << t.top() << endl;
	// t.pop();
	// cout << "t.pop=" << t.top() << endl;
	// t.pop();

	// cout << "t.min=" << t.min() << endl;

	t.push(33);
	t.push(777);

	cout << "t.min=" << t.min() << endl;

	return 0;
}
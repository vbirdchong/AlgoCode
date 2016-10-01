
/*
Subject:
How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element? Push, pop and min should all operate in O(1) time.

*/


#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

const int MAX_INT = ~(1 << 31);




class stack{
typedef struct node{
  int val;
  int min;
}node;

public:
  stack(int size = 10){
    node *m_buf = new node[size];
    m_buf[0].min = MAX_INT;
    m_cur = 0;
	cout << "m_buf[0].min = " << m_buf[0].min << endl;
  }

  ~stack(){
	//if (m_buf)
		//delete [] m_buf;
  }

  void push(int val){
    m_buf[++m_cur].val = val;
	cout << "bb: " << m_buf[m_cur-1].min << " vv: " << val << "m_cur: " << m_cur << "val: " << m_buf[m_cur - 1].val << "" << endl;
    if(m_buf[m_cur-1].min > val){
      m_buf[m_cur].min = val;
	  cout << "aa " << val << endl;
    }
    else{
      m_buf[m_cur].min = m_buf[m_cur-1].min;
    }
    cout << m_cur << " " << m_buf[m_cur].val << " " << m_buf[m_cur].min << " cur-1 min: " << m_buf[0].min << endl;
  }

  int pop(){
    int ret = m_buf[m_cur].val;
    m_cur--;
    return ret;
  }

  int min(){
    return m_buf[m_cur].min;
  }

  int top(){
    return m_buf[m_cur].val;
  }

private:
  node *m_buf;
  int m_cur;
};


int main(){
  stack test_stack(10);

  for(int i = 0; i < 10; i++){
	int rad = rand();
	test_stack.push(rad);
  }

  cout << "top value = " << test_stack.top() << endl;
  cout << "min value = " << test_stack.min() << endl;

  test_stack.push(-100);
  cout << "min value = " << test_stack.min() << endl;

  return 0;
}



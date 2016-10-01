
/*
Subject:
Describe how you could use a single array to implement three stacks.

*/

#include <iostream>

using namespace std;

class stack{
public:
  stack(int size = 300){
    m_buf = new int[size*3];
    m_ptop[0] = -1;
    m_ptop[1] = -1;
    m_ptop[2] = -1;
    m_size = size;
  }

  ~stack(){
    delete [] m_buf;
  }

  void push(int idx_stack, int value){
    int index = idx_stack * m_size + m_ptop[idx_stack] + 1;
    m_buf[index] = value;
    m_ptop[idx_stack]++;
  }

  int pop(int idx_stack){
    int index = idx_stack * m_size + m_ptop[idx_stack];
    int ret = m_buf[index];
    m_ptop[idx_stack]--;
    return ret;
  }

  int top(int idx_stack){
    int index = idx_stack * m_size + m_ptop[idx_stack];
    return m_buf[index];
  }

  bool is_empty(int idx_stack){
    m_ptop[idx_stack] == -1;
  }

private:
  int *m_buf;
  int m_ptop[3];
  int m_size;
};


class stack_ptr{
  typedef struct node{
    int data;
    int pre;
  }node;

public:
  stack_ptr(int size = 100){
    m_node = new node [size];
    m_size = size;
    m_cur = 0;
  }

  ~stack_ptr(){
    delete [] m_node;
  }

  void push(int idx_stack, int value){
    m_node[m_cur].data = value;
    m_node[m_cur].pre = m_ptop[idx_stack];
    m_ptop[idx_stack] = m_cur;
    ++m_cur;
  }

  int pop(int idx_stack){
    int index = m_ptop[idx_stack];
    int ret = m_node[index].data;
    m_ptop[idx_stack] = m_node[index].pre;
    return ret;
  }

  int top(int idx_stack){
    return m_node[m_ptop[idx_stack]].data;
  }

  bool is_empty(int idx_stack){
    m_ptop[idx_stack] == -1;
  }

private:
  node *m_node;
  int m_ptop[3];
  int m_size;
  int m_cur;
};

int main(){
  //stack test_stack;
  stack_ptr test_stack;

  for (int i = 0; i < 10; i++){
    test_stack.push(0, i);
  }

  for (int i = 10; i < 20; i++){
    test_stack.push(1, i);
  }

  for (int i = 20; i < 30; i++){
    test_stack.push(2, i);
  }

  for (int j = 0; j < 3; j++){
    cout << "stack:" << j << " top value = " << test_stack.top(j) << endl;
  }

  cout << "pop the value" << endl;

  for (int i = 0; i < 3; i++){
    cout << "stack:" << i << " pop the value= " << test_stack.pop(i) << endl;
  }

  test_stack.push(0, 111);
  test_stack.push(1, 222);
  test_stack.push(2, 333);

  for (int j = 0; j < 3; j++){
    cout << "stack:" << j << " top value = " << test_stack.top(j) << endl;
  }
  
  return 0;
}


# Solution Note

## 1. A + B 问题

给出两个整数a和b, 求他们的和, 但不能使用 + 等数学运算符。

说明

a和b都是 32位 整数么？是的

我可以使用位运算符么？当然可以

样例

如果 a=1 并且 b=2，返回3

### Solution

```
使用位运算，^ 操作是去掉进位后两个数相加的和，& 操作可以知道哪一位需要进行进位，通过左移进位数直到为0，这样就可以把所有需要进位的全部计算完毕

Java

public int aplusb(int a, int b) {
    while (b != 0) {
        int sum_val = a ^ b;
        int carry = (a & b) << 1;
        a = sum_val;
        b = carry;
    }
    return a;
}

Python没有类型定义，所以会产生b!=0的问题，使用ctypes中类型转化即可以解决

def aplusb(self, a, b):
    a = ctypes.c_int32(a).value
    b = ctypes.c_int32(b).value
    while(b != 0) :
        sum_val = ctypes.c_int32(a ^ b).value
        carry_val = ctypes.c_int32(a & b).value
        b = ctypes.c_int32(carry_val << 1).value
        a = sum_val
    return a

```
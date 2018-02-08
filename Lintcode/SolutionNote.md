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

## 114. 不同的路径

有一个机器人的位于一个 m × n 个网格左上角。

机器人每一时刻只能向下或者向右移动一步。机器人试图达到网格的右下角。

问有多少条不同的路径？

样例

给出 m = 3 和 n = 3, 返回 6.

给出 m = 4 和 n = 5, 返回 35.

### Solution

```
属于动态规划问题，当前网格的路径数取决于到达它左侧网格和正上方网格的路径的和

Java

public int uniquePaths(int m , int n) {
    if (m == 1 || n == 1) {
        return 1;
    }

    int[][] cell = new int[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                cell[i][j] = 1; 
            } else {
                cell[i][j] = cell[i - 1][j] + cell[i][j - 1];
            }
        }
    }

    return cell[m - 1][n - 1];
}

Python

def uniquePaths(self, m, n):
    if (m == 1 or n == 1):
        return 1

    # function 1
    cell = [[0 for col in range(n)] for row in range(m)]
    for i in range(0, m):
        for j in range(0, n):
            if (i == 0 or j == 0):
                cell[i][j] = 1
            else:
                cell[i][j] = cell[i-1][j] + cell[i][j-1]
    return cell[m-1][n-1]

    # function 2
    # using mapping 
    # mp = {}
    # for i in range(m):
    #     for j in range(n):
    #         if(i == 0 or j == 0):
    #             mp[(i, j)] = 1
    #         else:
    #             mp[(i, j)] = mp[(i - 1, j)] + mp[(i, j - 1)]
    # return mp[(m - 1, n - 1)]
```
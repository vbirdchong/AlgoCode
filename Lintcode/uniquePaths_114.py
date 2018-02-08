#! pythons3

class Solution:
    """
    @param: m: positive integer (1 <= m <= 100)
    @param: n: positive integer (1 <= n <= 100)
    @return: An integer
    """
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

def main():
    test = Solution()
    # if the integer result too large, it will print error result
    print(test.uniquePaths(9,99))

if __name__ == '__main__':
    main()
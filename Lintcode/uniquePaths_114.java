
public class uniquePaths_114 {
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

    public static void main(String[] args) {
        uniquePaths_114 test = new uniquePaths_114();
        System.out.print(test.uniquePaths(9, 99));
    }
}
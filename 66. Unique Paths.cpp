class Solution {
public:
    int uniquePaths(int m, int n) {
        int A[102][102] = {};
        A[0][1] = 1;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                A[i][j] = A[i][j-1] + A[i-1][j];
        return A[m][n];
    }
};
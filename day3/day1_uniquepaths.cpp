class Solution
{
public:
    int dp[105][105];
    int helper(int row, int col, int m, int n)
    {
        if (row == m && col == n)
            return 1;
        if (row > m || col > n)
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];

        return dp[row][col] = helper(row + 1, col, m, n) + helper(row, col + 1, m, n);
    }

    int uniquePaths(int m, int n)
    {
        memset(dp, -1, sizeof(dp));

        return helper(0, 0, m - 1, n - 1);
    }
};
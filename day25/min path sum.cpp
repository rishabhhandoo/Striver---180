class Solution {
public:
    int dp[202][202];
    int helper(int i,int j,vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        //base case
        if(i==n-1 && j==m-1)    return grid[n-1][m-1];
        else if(i>=n || j>=m)   return INT_MAX;
        else if(dp[i][j] != -1) return dp[i][j];
        //calls
        int down = helper(i+1,j,grid);
        int right = helper(i,j+1,grid);

        return dp[i][j] = grid[i][j] + min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,grid);
    }
};
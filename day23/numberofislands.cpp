class Solution {
public:
    
    bool dfs(int i , int j ,vector<vector<char>>& grid,vector<vector<int>> &vis,int n , int m)
    {
        // condition to return true
        if(i<0 || i>=n|| j<0 || j>=m || vis[i][j]==1)
        {
            return true;
        }
        if(grid[i][j]=='0')
            return true;
        vis[i][j]=1;
        
        bool r1 = dfs(i+1,j,grid,vis,n,m);
        bool r2 = dfs(i,j+1,grid,vis,n,m);
        bool r3 = dfs(i-1,j,grid,vis,n,m);
        bool r4 = dfs(i,j-1,grid,vis,n,m);
        
        return r1&&r2&&r3&&r4;


    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]=='1')
                {
//matlab uspr jao // increase the counter if all the edges gieva  specific result
                    bool r1 = dfs(i+1,j,grid,vis,n,m);
                    bool r2 = dfs(i,j+1,grid,vis,n,m);
                    bool r3 = dfs(i-1,j,grid,vis,n,m);
                    bool r4 = dfs(i,j-1,grid,vis,n,m);
                    
                    if(r1&&r2&&r3&&r4) ans++;
                    
                }
            }

        }
        return ans;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        // vector<vector<int>> vis(n,vector<int>(m,0));
        int min=0;
        int countr=0;
        int countf=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    cout<<"found fresh"<<endl;
                    countf++;
                }
                else if(grid[i][j]==2)
                {
                    cout<<"found rotten";
                    countr++;
                    cout<<i<<" "<<j<<endl;
                    q.push({i,j});
                }
            }
        }
        if(countf==0)   return 0;
        if(q.empty() && countf>0)   return -1;
        
        while(!q.empty())
        {
            cout<<"-------------check - 1--------------"<<endl;
            int size=q.size();
            bool flag = true;
            for(int i=0;i<size;i++)
            {
            cout<<"-------------check - 2--------------"<<endl;
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                //up
                if(x-1>=0 && grid[x-1][y]==1)
                {
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                    flag=false;
                    countf--;
                }
                //right
                if(x+1<n  && grid[x+1][y]==1)
                {
                    cout<<"right"<<endl;
                    grid[x+1][y]=2;
                    q.push({x+1,y});
                    flag=false;
                    countf--;
                }
                // up
                if(y-1>=0 && grid[x][y-1]==1)
                {
                    cout<<"up"<<endl;
                    grid[x][y-1]=2;
                    q.push({x,y-1});
                    flag=false;
                    countf--;
                }
                //down
                if(y+1<m && grid[x][y+1]==1)
                {
                    cout<<"down"<<endl;
                    grid[x][y+1]=2;
                    q.push({x,y+1});
                    flag=false;
                    countf--;
                }

            }
            if(flag==false) min++;
            if(countf==0) return min;
            
        }
        
        //now we start with bfs
        
        return -1;
        
    }
};


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<int>> vis(n,vector<int>(m,0));
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(image[x][y]!=color )
            {
                int old_color=image[x][y];
                image[x][y]=color;
                //traverse for the other sides
                //left
                if(y-1>=0 && image[x][y-1]==old_color&& vis[x][y-1]==0)
                {
                    q.push({x,y-1});
                    vis[x][y-1]=1;
                    
                }
                //right
                if(y+1<m && image[x][y+1]==old_color&& vis[x][y+1]==0)
                {
                    q.push({x,y+1});
                    vis[x][y+1]=1;
                }
                //up
                if(x-1>=0 && image[x-1][y]==old_color&& vis[x-1][y]==0)
                {
                    q.push({x-1,y});
                    vis[x-1][y]=1;
                }
                //left
                if(x+1<n && image[x+1][y]==old_color&& vis[x+1][y]==0)
                {
                    q.push({x+1,y});
                    vis[x+1][y]=1;
                }
            }
        }
    return image;
    }
};
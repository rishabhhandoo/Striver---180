class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        
        
        int n = isConnected.size();
        int src=0;
        int ans=0;
        queue<int> q;
        vector<int> vis(n+1,0);
        for(int i=0;i<n;i++)
        {
            
            src = i;
            if(vis[i]==0)
            {
                ans++;
                q.push(src);
                vis[src]=1;
               while(!q.empty())
               {
                   int node = q.front();
                   q.pop();
                   cout<<node<<endl;
                   for(int x=0;x<n;x++)
                     {
                        if(isConnected[node][x]==1 && vis[x]==0)
                        {
                            q.push(x);
                            vis[x]=1;
                        }
                     }  
               }
              
            }
            
        }
        return ans;
        
    }
};
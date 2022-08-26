class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> vis(n,0);
        vector<int> adj[n]; 
        vector<int> ind(n,0);
        
        for(auto itr : pre)
        {
            adj[itr[1]].push_back(itr[0]);
            ind[itr[0]]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
            }
        }
        
        while(q.empty() == false)
        {
            int ele = q.front();
            vis[ele]=1;
            q.pop();
            
            for( auto itr : adj[ele])
            {
                if(vis[itr]==0)
                {
                    ind[itr]--;
                    if(ind[itr]==0)
                    {
                        q.push(itr);    
                    }
                }
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(ind[i]!=0)
            {
                return false;
            }
            
        }
        
        return true;        
    }
};
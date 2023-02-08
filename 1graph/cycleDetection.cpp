//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  
  bool check(int node,vector<int> adj[],vector<bool> vis)
  {
      queue<pair<int,int>> q;
      vis[node]=1;
      
      q.push({node,-1});
      
      
      while(!q.empty())
      {
          int curr = q.front().first;
          int prev = q.front().second;
          q.pop();
          for(auto itr:adj[curr])
          {
              if(vis[itr]!=1)
              {
                  vis[itr]=1;
                  q.push({itr,curr});
              }else if(itr != prev)
              {
                  return true;
              }
          }
          
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool> vis(V+1,false);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]!=1)
            {
                if(check( i,adj,vis) )
                    return true;
            }
        }
        
        
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
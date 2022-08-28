//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int n, vector<int>adj[]){
	    //using bfs
	    vector<pair<int,int>>vis (n,{0,-1});
	    
	    //colors are 1 and 2
	    
	    queue<pair<int,int>> q;
	    
	    for(int i =0;i<n;i++)
	    {
	        //here we dont care about the color as this situation would only be trigered for disconnected components
	        if(vis[i].first ==0)
	        {
	            q.push({i,1});
	            vis[i].first = 1;
	            vis[i].second = 1;
	        }
	        
	        
	        while(!q.empty())
	        {
	            int parent = q.front().first;
	            int color = q.front().second;
	            q.pop();
	            vis[parent].first=1;
	            vis[parent].second=color;
	            for(auto node : adj[parent])
	            {
	                if(vis[node].first == 0)
	                {
	                    int c = color==1 ? 2 : 1;
	                    
	                    q.push({node,c});
	                }else {
	                    if(vis[node].second == color)
	                    {
	                        return false;
	                    }
	                }
	            }
	        }
	        
	        
	        
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
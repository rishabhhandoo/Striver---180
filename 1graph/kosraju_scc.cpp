//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

  
class Solution
{
    

public:
    void dfs(int node,vector<int>&visit,vector<vector<int>>& adj,stack<int>&stk){
        visit[node]=1;
        for(auto it:adj[node])
            if(!visit[it])
             dfs(it,visit,adj,stk);
        stk.push(node);     
    }

    void dfs2(int node,vector<int>&visit,vector<vector<int>>& adj){
        visit[node]=1;
        for(auto it:adj[node])
            if(!visit[it])
             dfs2(it,visit,adj);
    }	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)  
    {
        //code here
        vector<int>visit(V,0);
        stack<int>stk;
        for(int i=0;i<V;i++){
            if(!visit[i])
                dfs(i,visit,adj,stk);
        }
        vector<vector<int>>adjT(V);
        for(int i=0;i<V;i++){
            visit[i]=0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        int ans{};
        while(stk.size()){
            int node=stk.top();
            stk.pop();
            if(!visit[node]){
                ans++;
                dfs2(node,visit,adjT);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
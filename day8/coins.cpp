//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
// 	int dp[1000005][1000005];
	int helper(int ind,int val ,int coins[],int m,int v,vector<vector<int>>&dp)
	{
	    //base case
	    if(val>v|| ind>=m)
	    {
	        return INT_MAX;
	    }
	    if(val==v)
	    {
	        return 0;
	    }
	    
	    if(dp[ind][val]!=-1)    return dp[ind][val];
	    
	    
	    
	        //take
	       long long res1 =  helper(ind,val+coins[ind],coins,m,v,dp)+1LL ;
	        //not take
	       long long res2 =  helper(ind+1,val,coins,m,v,dp) +0LL;
	    
	    
	    return dp[ind][val] = min(res1,res2);
	    
	    
	}
	
	int minCoins(int coins[], int m, int v) 
	{ 
	    if(v==0)    return 0;
	    vector<vector<int>>dp(m+1,vector<int>(v+1,-1));
	   // memset(dp,-1,sizeof(dp));
	    int index=0;
	    int val=0;
	    int num=0;
	    int ans= helper(index,val,coins,m,v,dp);
	    return (ans==INT_MAX)? -1 : ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
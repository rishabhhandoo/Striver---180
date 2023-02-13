//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    vector<vector<int>> dp = decltype(dp)(202, vector<int>(202, -1));
    public:
    
    int eggDrop(int egg, int flr)   
    // FIND THE BEST OF WORSTS CASES
    {
        // pep-coding
        
        
        if(egg==0)
            return INT_MAX;
        
        if(egg==1)
            return flr;
        
        if(flr==1)
            return 1;
            
        if(flr==0)
            return 0;
            
        if(dp[egg][flr] != -1)
            return dp[egg][flr];
        
        int mini = INT_MAX;
        for(int f = 1; f <=flr; f++){
            // choices of floors
            
            // min of worsts cases
            mini = min(mini, max(eggDrop(egg-1, f-1), //  egg will break
    eggDrop(egg, flr-f))); // will survive
            
        }
        
        return dp[egg][flr] = mini+1; 
    }
    
    
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
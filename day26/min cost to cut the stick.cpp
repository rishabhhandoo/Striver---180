class Solution {
public:
    int dp[101][101];
    int helper(int i,int j,vector<int>& cuts)
    {
        // base case
        if(i>j) return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        //now going to do all the possible cuts 
        int mini=INT_MAX;
        for(int k=i;k<=j;k++)
        {
            int cut =  cuts[j+1]-cuts[i-1]  + helper(i,k-1,cuts) + helper(k+1,j,cuts);
            mini = min(cut,mini);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        memset(dp,-1,sizeof(dp));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        //recursive function
        return helper(1,c,cuts);
    }
};
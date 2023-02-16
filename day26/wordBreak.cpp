class Solution {
public:
    int dp[1005][1005];
    bool fun(string &s, int i, int j, vector<string> &dict)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(find(dict.begin(),dict.end(),s.substr(i,j-i+1))!=dict.end())
            return dp[i][j] = true;
        
        for(int k = i+1;k<=j;k++)
        {
            if(fun(s,i,k-1,dict) && fun(s,k,j,dict))
                return dp[i][j] = true;
        }
        
        return dp[i][j] = false;
    }
    bool wordBreak(string s, vector<string>& dict) 
    {   
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        return fun(s,0,n-1,dict);
    }
};
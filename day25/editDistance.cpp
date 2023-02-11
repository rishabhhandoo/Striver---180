class Solution {
public:
int dp[501][501];
    int helper(int i,int j,string s1,string s2)
    {
        if(i==s1.size()&& j!=s2.size())
        {
            return s2.size()-j;
        }
        if(j==s2.size())
        {
            return s1.size()-i;
        }
        if(dp[i][j]!=-1)    return dp[i][j];
        if(s1[i]==s2[j])   return dp[i][j]=helper(i+1,j+1,s1,s2);
        return dp[i][j] = 1 + min({helper(i+1,j+1,s1,s2),helper(i+1,j,s1,s2),helper(i,j+1,s1,s2)}
);

    }
    int minDistance(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        // if(s1.size()==0)    return s2.size();
        return helper(0,0,s1,s2);
    }
};
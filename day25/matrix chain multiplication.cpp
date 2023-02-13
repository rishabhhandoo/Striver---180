class Solution{
public:
    int dp[505][505];
    int solve(int arr[],int i,int j){
        if(i>=j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k=i;k<j;k++){
            int tempans = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
            mini = min(mini,tempans);
        }
        return dp[i][j] = mini;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        int i = 1,j = N-1;
        return solve(arr,i,j);
        
    }
};
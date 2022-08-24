int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
        
    int low = 1;
    int high = stalls[n-1] - stalls[0];
    int ans=0;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        int prev=stalls[0];
        int cows=1;
        for(int i=0;i<n;i++)
        {
            if(mid<= stalls[i]-prev)
            {
                prev = stalls[i];
                cows++;
            }
        }
        
        if(cows >= k)
        {
            low=mid+1;
        }else{
            high=mid-1;
        }
        ans = max(ans,mid);
    }
    return high;
}
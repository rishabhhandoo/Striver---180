int count(vector<vector<int>> &matrix,int num)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int l=0;
        int r=m-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            
            if(matrix[i][mid] > num)
            {
                r=mid-1;
            }else
                l=mid+1;
        }
        ans+=l;
            
    }
    return ans;
}

int getMedian(vector<vector<int>> &matrix)
{
    int l = 1;
    int r = 1e5;
    int n = matrix.size();
    int m = matrix[0].size();
    int middle = (n*m)/2;
    
    while(l<=r)
    {
        int mid = l + (r-l)/2;
        //seeing how many are smaller and larger
        int smaller=count(matrix,mid);
        
        if(smaller > middle)    
              r=mid-1;
        else
            l=mid+1;   
    }
    return l;
}
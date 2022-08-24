int Solution::books(vector<int> &A, int B) {
    
    int high=0,low=A[0];
    
    for(int i=0;i<A.size();i++)
    {
        high+=A[i];
        low = min(low,A[i]);
    }
    int ans=0;
    
    while(low<=high)
    {
        int mid = (low + high) >> 1;
        int kids = 0;
        int books =0;
        
        for(int i=0;i<A.size();i++)
        {
            if(A[i]>mid){
                low=mid+1;
                break;
            }
            
            if(books+A[i]<=mid)
            {
                books+=A[i];
            }
            else
            {
                books=A[i];
                kids++;
            }
        }
        
        if(kids<B)
        {
            // ans = mid;
            high=mid-1;
        }else
        {
            low=mid+1;
        }
        
    }
    return low;
}

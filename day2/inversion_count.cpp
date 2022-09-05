//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[],long long temp[],long long left,long long mid,long long right)
    {
        long long i,j,k;
        i=left;
        j=mid;
        k=left;
        long long invCount=0;
        
        while((i<=mid-1) && (j<= right))
        {
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }
            else {
                temp[k++] = arr[j++];
                invCount = invCount + (mid-i);
            }
        }
        
        while(i<=mid-1)
        {
            temp[k++]=arr[i++];
        }
        while(j<=right)
        {
            temp[k++]=arr[j++];
        }
        
        for(i=left;i<=right;i++)
        {
            arr[i]=temp[i];
        }
        return invCount;
    }
    
    
    long long mergesort(long long arr[],long long temp[],long long left,long long right)
    {
        long long mid , invCount=0;
        
        if(right>left)
        {
            mid = (right+left)/2;
            invCount += mergesort(arr,temp,left,mid);
            invCount += mergesort(arr,temp,mid+1,right);
            
            invCount += merge(arr,temp,left,mid+1,right);
            
        }
    
        return invCount;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        long long ans = mergesort(arr,temp,0,N-1);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
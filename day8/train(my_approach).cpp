//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int start[], int end[], int n)
    {
        if(n==0)    return 0;	
    	vector<pair<int,int>> slot;
       
        vector<int> platform(n,0);
        // platform[0]=0;
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            slot.push_back({end[i],start[i]});
        }
        
        sort(slot.begin(),slot.end());
        
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                if(slot[i].second > platform[j])
                {
                    platform[j]=slot[i].first;
                    ans=max(ans,j+1);
                    break;
                }
            }
            
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends
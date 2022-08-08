//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void helper(int csum , vector<int> &ans , vector<int> &arr , int n)
    {
        if(n<0)
        {
            ans.push_back(csum);
            return ;
        }
        
        //take
        helper(csum + arr[n],ans,arr,n-1);
        
        //not take
        helper(csum , ans , arr , n-1);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        // ans.push_back(0);
        helper(0,ans,arr,N-1);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
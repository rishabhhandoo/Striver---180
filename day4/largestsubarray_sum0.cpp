//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   unordered_map<int,int> map;
        int sum=0;
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            if(sum==0){
                maxx=i+1;
            }else{
                if(map.find(sum)==map.end()){
                   map[sum]=i;
                }else{
                    maxx=max(maxx,i-map[sum]);
                }
            }
            
        }
        return maxx;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
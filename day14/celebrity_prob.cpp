//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        stack<int> st;
        
        for(int i=n-1;i>=0;i--) st.push(i);
        
        while(st.size()>1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(m[a][b]==1)
            {
                st.push(b);
            }else{
                st.push(a);
            }
        }
        
        int celeb = st.top();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(m[celeb][i]==1)  return -1;
            if(m[i][celeb]==0)  count++;
        }
        if(count==1)
        return celeb;
        
        return -1;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
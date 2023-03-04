#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ispalindrome(string s)
    {
        string temp=s;
        reverse(s.begin(),s.end());
        return s==temp;
    }
    void helper(int l,int r,vector<string> &curr,string &s,vector<vector<string>> &ans)
    {
        if(l==r ){
            ans.push_back(curr);
            return;
        }
        //partinoning
        for(int i=l;i<r;i++)       
        {
            if(ispalindrome(s.substr(l,i-l+1)))
            {
                curr.push_back(s.substr(l,i-l+1));
                helper(i+1,r,curr,s,ans);
                curr.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        helper(0,s.size(),curr,s,ans);       
        return ans; 
    }
};



class Solution {
public:
    bool partition(string s, int index,int i)
    {
        while(index<i)
        {
            if(s[index++]!=s[i--])
                return false;
        }
        return true;
    }
    
    void helper(int index,string s,vector<string> curr,vector<vector<string>> &ans)
    {
        //base case
        if(index==s.size())
        {
            ans.push_back(curr);
            return;
        }
        
        
        for(int i=index;i<s.size();i++)
        {
            //check for palindrome till i from index
            if(partition(s,index,i))
            {
                string ad="";
                for(int k=index;k<=i;k++)
                {
                    ad+=s[k];
                }
                curr.push_back(ad);
                helper(i+1,s,curr,ans);
                curr.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        
        vector<string> curr;
        int index=0;
        int partition=0;
        helper(index,s,curr,ans);
        
        return ans;
    }
};
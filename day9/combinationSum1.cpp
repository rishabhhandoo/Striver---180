class Solution {
public:
    
    void helper(int k,int target,vector<int> p,vector<int> up,vector<vector<int>> &ans)
    {
        if(target==0)
        {
            ans.push_back(p);
            return;
        }else if(target <0)
        {
            return;
        }
        
        
         for(int i=k;i<up.size();i++)
         {
             //recursive call
             p.push_back(up[i]);
             helper(i,target-up[i],p,up,ans);
             p.pop_back();
         }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> p;
        
        
        helper(0,target,p,candidates,ans);
        
        return ans;
    }
};
class Solution {
public:
    // set<vector<int>> s;
    
    
    void helper(int index,vector<int> order,vector<vector<int>> &ans,vector<int>& candidates, int target)
    {
        
        if(target<0)
        {
            return; 
        }
        else if(target==0)
        {
            ans.push_back(order);
            return;
        }

        for(int i=index;i<candidates.size();i++)
        {
            if(i>index && candidates[i]==candidates[i-1])
                continue;
            
            if(candidates[i]>target)
                break;  
                // /take
                order.push_back(candidates[i]);
                // target-=candidates[i];
                helper(i+1,order,ans,candidates,target-candidates[i]);
                //not take
                order.pop_back();
            
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector <vector<int> > ans;
        vector<int> curr;
        int index=0;
        sort(candidates.begin(),candidates.end());
        helper(index,curr,ans,candidates,target);
                    
        return ans;
    }
};
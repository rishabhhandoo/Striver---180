class Solution {
public:
    
    set<vector<int>> check;

void helper(int ind,vector<int> &arr,vector<int> p,vector<vector<int>> &ans)
{
    if(ind<0)
    {
//         sort(p.begin(),p.end());
        //also insert the finding step here
        if(check.find(p) == check.end())
        {
            ans.push_back(p);
            check.insert(p);
        }
        return;
        
    }
    //not takig
    helper(ind-1,arr,p,ans);
    //take
    p.push_back(arr[ind]);
    helper(ind-1,arr,p,ans);
    
    //for backtracking
    p.pop_back();
}

    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> p;
    vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
    int n= nums.size();
    helper(n-1,nums,p,ans);
    
    return ans;
    }
};
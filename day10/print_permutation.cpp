
//or u could use the  basic approach of taking and not taking usig the i and index approach 

class Solution {
private:
    void solve(vector<int>nums,vector<vector<int>> &ans, int index){
        //base condition
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            swap( nums[i] , nums[index] );
            solve(nums,ans,index+1);
            swap( nums[i] , nums[index] );

        }
        
    }
    public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        int index;
        vector<vector<int>> ans;
        
        solve(nums,ans,index);
        return ans;
    }
};
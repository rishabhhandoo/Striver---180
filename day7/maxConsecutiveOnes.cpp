class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxx=0;
        int curr=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1){
                curr++;
            }else curr=0;
            
            maxx=max(maxx,curr);
        }
    return maxx;
    }
};
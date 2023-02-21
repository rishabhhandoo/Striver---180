class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj =nums[0];
        int count=1;

        for(int i=1;i<nums.size();i++)
        {
            if(count==0)
            {
                maj=nums[i];
                count=1;
            }else if(maj==nums[i])
            {
                count++;
            }else   count--;
        }
        return maj;
    }
};
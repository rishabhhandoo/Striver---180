class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return;
        
        int n= nums.size();
        int k,l;
        
        // cout<<"initial i "<<i<<endl;
        
        for(k=n-2;k>=0;k--)
        {
            if(nums[k]<nums[k+1])
            {
                break;
            }
        }
        if(k<0)
        {
            reverse(nums.begin(),nums.end());
        }else{
            for(l=n-1;n>k;l--)
            {
                if(nums[l]>nums[k]){
                    break;
                }
            }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
        
        
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int ans = *max_element(nums.begin(),nums.end());
        int maxi=1;
        int mini=1;
        for(int i=0;i<n;i++)
        {
                if(nums[i]>0){
                    if(maxi<=0)maxi=nums[i];
                    else    maxi*=nums[i];
                    mini*=nums[i];
                }else if(nums[i]<=0){
                        int temp1=maxi;
                    int temp2=mini;
                      maxi=max(temp2*nums[i],nums[i]);
                      mini=min(temp1*nums[i],nums[i]);
                }  
            cout<<nums[i]<< " "<<"maxi : "<<maxi<<" mini : "<<mini<<endl;
                    ans = max(maxi,ans);
        }
        
        return ans;
    }
};
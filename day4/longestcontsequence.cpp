class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> umap;
        int n = nums.size();
        if(n==0 || n==1)    return n;
        for(int i=0;i<n;i++)umap[nums[i]]++;
        int ans=1;
        for(int i=0;i<n;i++){
            if(umap.find(nums[i]-1)==umap.end() && umap.find(nums[i]+1)!=umap.end()){
                int k=0;
                while(true){
                    if(umap.find(nums[i]+k)!=umap.end()){
                        k++;
                    }else   break;
                }
                ans=max(ans,k);
            }
        }
        return ans;
    }
};
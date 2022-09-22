class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n=nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(!q.empty() && (i-k)==q.front())
            {
                q.pop_front();
            }
            
            while(!q.empty() && nums[i]>nums[q.back()])
            {
                    q.pop_back();
            }
            
            q.push_back(i);
            
            if(i>=k-1)  ans.push_back(nums[q.front()]);
            
        }
        return ans;
    }
};
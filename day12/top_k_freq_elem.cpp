class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int> map;
        if(nums.size()==0) return nums;
        for(auto it : nums){
            map[it]++;
        }
        
        priority_queue<pair<int,int>> pq;
        
        for(auto itr=map.begin();itr!=map.end();itr++)
        {
            pq.push({(*itr).second,(*itr).first});
            if(pq.size() > (int)map.size()-k){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};
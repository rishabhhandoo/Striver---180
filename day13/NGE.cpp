class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         //first createa nge array 
        int n=nums2.size();
        vector<int> nge2(n);
        stack <int> s;
        s.push(nums2[n-1]);
        nge2[n-1] = -1;
        
        vector<int> ans(nums1.size());
        
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() && s.top()<= nums2[i])
            {
                s.pop();
            }
            
            if(!s.empty())
            {
                nge2[i]=s.top();
            }else{
                nge2[i]=-1;
            }
            s.push(nums2[i]);
        }
        
        
         //then iterator to find the index and then return the nge
        
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    ans[i]=nge2[j];
                    break;
                    
                }
            }
        }
        return ans;
    }
};
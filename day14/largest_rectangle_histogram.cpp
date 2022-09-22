class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans;
        int n = heights.size();
        stack<int> s1;
        stack<int> s2;
        vector<int> l(n);
        vector<int> r(n);

        //first calculate the left
        for(int i=0;i<n;i++)
        {
            while(!s1.empty() && heights[s1.top()]>=heights[i])
            {
                s1.pop();
            }
            
            if(!s1.empty()) l[i]=s1.top()+1;
            else    l[i]=0;
            
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!s2.empty() && heights[s2.top()]>=heights[i])
            {
                s2.pop();
            }
            
            if(!s2.empty()) r[i]=s2.top()-1;
            else    r[i]=n-1;
            
            s2.push(i);
        }
        
        for(int i=0;i<n;i++)
        {
            ans = max(ans,(abs(l[i]-r[i])+1)*heights[i]);
        }
            return ans;
    }
};
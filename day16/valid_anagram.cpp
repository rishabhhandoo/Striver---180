class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() < t.size()) return false;
        unordered_map<char,int> freq;
        
        for(auto itr : s)
        {
            freq[itr]++;
        }
        int count = freq.size();
        
        for(auto itr : t)
        {
            freq[itr]--;
            if(freq[itr] ==0)
            {
                count--;
            }
        }
        
        return count==0? true : false;
    }
};
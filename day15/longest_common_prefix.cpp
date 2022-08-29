class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string word = strs[0];
        
        for(int i=1 ; i < strs.size() ; i++)
        {
             int j=0;
            string new_word="";
            
            while(j<word.size() && j< strs[i].size())
            {
                if(word[j] == strs[i][j])
                {
                    new_word+=word[j];
                }else{
                    break;
                }
                
                j++;
                
            }
            word = new_word;
        }
        return word;
    }
};
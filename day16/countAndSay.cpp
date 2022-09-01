class Solution {
public:    
    void helper(int n,int itr,string &prev)
    {
        if(itr>n)    
            return;
        char pnum = prev[0];
        int count=1;
        
        string abhi="";
        for(int i=1;i<prev.length();i++)
        {
            if(pnum == prev[i])
            {

            count++;
            }
            else{
                abhi+= to_string(count) + pnum;
                pnum = prev[i];
                count=1;
            }
        } 
        abhi+= to_string(count) + pnum;
        prev = abhi;
        
        helper(n,itr+1,prev);
        
    }
        
    
    string countAndSay(int n) {
        string prev="1";
        if(n==1)
            return prev;
        
        string ans="";
        // string prev="1";
        helper(n,2,prev);
        return prev;
    }
};
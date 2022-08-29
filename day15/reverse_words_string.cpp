class Solution {
public:
    string reverseWords(string s) {
        
        
        int strt=0;
        int ed=s.size()-1;
        string ans="";
        
        while(s[strt] == ' ')
        {
            strt++;   
        }
        
        while(s[ed] == ' ')
        {
            ed--;   
        }
        
        int aage=ed;
        int peeche=ed;
        
        for(int i=ed;i>=strt;i--)
        {
            if(i<ed && s[i+1]==' ' && s[i]!=' ')
            {
                peeche=i;
            }
            
            
            if( i==strt || s[i-1]==' ' && s[i]!=' ')
            {
                aage=i;
                
                for(int j=aage;j<=peeche;j++)
                {
                    ans+=s[j];
                }
                if(i!=strt)
                    ans.push_back(' ');
                
                // peeche = i-2;
            }
        }
        return ans;
        
    }
};
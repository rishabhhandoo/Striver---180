class Solution {
public:
    int myAtoi(string s) {
                
        bool flag=0;
        int strt =0;
        int n =s.length();
        long long res = 0;
        int limit = INT_MAX;
        
        while(strt < n && s[strt]==' ')
        {
            cout<<"s"<<endl;
            strt++;
        }
        
        if(strt == n )
            return 0;
        
        
        if(s[strt]=='-' || s[strt]=='+' || s[strt] -'0'<=9 && s[strt] -'0'>=0)
            {
                
                
                if(s[strt]=='-'){
                    flag=true;
                    if(s[strt+1]-'0'>9 || s[strt+1]-'0'<0)
                    {
                        return 0;
                    }
                    strt=strt+1;
                }
                if(s[strt]=='+')
                {
                    if(s[strt+1]-'0'>9 || s[strt+1]-'0'<0)
                    {
                        return 0;
                    }
                    strt++;
                }
                // cout<<"flag set"<<endl;
                 for(int i=strt;i<n && s[i]!=' ' && s[i] -'0'<=9 && s[i] -'0'>=0;i++)
                {           
                     cout<<s[i]<<" ";
                    res = res*10 + s[i] - '0';
                    if(res>limit)
                    {
                        break;
                    }
                }
            }else return 0;
       
        cout<<"vale of res "<< res<<" "<<limit<<endl;
        
        if(res > limit)
        {
            res = limit;
            return flag ? -(res+1) : res;
        }
        
        return flag ? -(res) : res;       
    }
};
class Solution {
public:
    int compareVersion(string v1, string v2) {
        
        int i=0,j=0;
        int a=0,b=0;
        while(i<v1.size() || j<v2.size())
        {
            while(i<v1.size() && v1[i]!='.' )
            {
                a=a*10 + (v1[i] -'0');
                i++;
            }
            
            while(j<v2.size() && v2[j]!='.')
            {
                b=b*10 + (v2[j] -'0');
                j++;
            }
            
            if(a>b)
            {
                return 1;
            }else if(b>a)
            {
                return -1;
            }
            i++;
            j++;
            a=0;
            b=0;
        }
        
        
        
        return 0;
        
    }
};
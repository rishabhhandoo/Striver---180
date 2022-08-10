class Solution {
public:
    
    bool strt(char ch)
    {
        if(ch =='(' || ch =='[' || ch == '{')
        {
            return true;
        }
        return false;
    }
    
    bool check(char abhi , char str)
    {
        switch(str){
            case ')' : 
                if(abhi == '(')
                    return true;
                    break;
            case '}' : 
                if(abhi == '{')
                    return true;
                    break;
            case ']' : 
                if(abhi == '[')
                    return true;
                    break;
            default:
                return false;
                break;
        }
        return false;
    }
    
    bool isValid(string s) {
        
        if(s.size()==1) return false;
        
        stack<char> st;
        
        for(int i=0;i<s.size();i++)
        {
            if(strt(s[i]))
                st.push(s[i]);
            else{
                if(!st.empty())
                    {
                        char abhi = st.top();
                    if(!check(abhi , s[i]))
                    {
                       return false;
                    }
                    st.pop();
                }else return false;
                
            }
        }
        
        if(!st.empty())
            return false;
        
        
        return true;
        
    }
};
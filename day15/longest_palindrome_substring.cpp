class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans=1;
        int fl=0;
        int fr=0;
        if(s[0]==s[1])    fr=1;
        for(int i=1;i<n;i++)
        {
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
            }
            l++;
            r--;
            if(r-l+1 > ans)
            {
                ans = max(ans , r-l+1);
                fl=l;
                fr=r;
            }
        }

        //oddlen res 
        string oddlen = s.substr(fl,fr-fl+1);
        fl=0;
        fr=0;
        if(s[0]==s[1])    fr=1;
        //case of even length
        int base =1;
        for(int i=0;i<n;i++)
        {
            int l=i;
            int r=i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
            }
            l++;
            r--;
            if(r-l+1 > base)
            {
                base = r-l+1;
                fl=l;
                fr=r;
            }
            cout<<fl<<fr<<endl;
        }
        cout<<fl<<fr<<endl;
        //evenlen res 
        string evenlen = s.substr(fl,fr-fl+1);
        cout<<"string: "<<evenlen<<endl;
        if(oddlen.size()>=evenlen.size())
            return oddlen;
        else    return evenlen;
    }
};
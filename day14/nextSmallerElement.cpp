vector<int> Solution::prevSmaller(vector<int> &a) {

int n = a.size();
vector<int> ans(n);
stack<int> s;

ans[0]=-1;
s.push(a[0]);

for(int i=1;i<n;i++)
{
    while(!s.empty() && s.top()>=a[i])
    {
        s.pop();   
    }
    
    if( !s.empty() )
    {
        if(s.top() < a[i])
        {
            ans[i]=s.top();
            s.push(a[i]);
        }
    }else{
        s.push(a[i]);
        ans[i]=-1;
    }
}

return ans;

}

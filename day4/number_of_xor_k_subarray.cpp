int Solution::solve(vector<int> &a, int b) {
    unordered_map<int,int> umap;
    int xorin=0;
    int ans =0;
    
    for(int i=0;i<a.size();i++)
    {
        xorin=xorin^a[i];
        if(xorin == b)
        {
            ans++;
        }
        if(umap.find(xorin^b)!=umap.end())
        {
            ans=ans+umap[xorin^b];
            umap[xorin]++;
        }else{
            umap[xorin]++;
        }
    }
    return ans;
    
}

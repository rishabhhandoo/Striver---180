#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    unordered_map<char,int> umap;
    int msize=0;
    int csize=0;
    
    for(int i=0;i<input.size();i++)
    {
        umap[input[i]]++;
        csize++;
        if(umap[input[i]] == 1){
            msize=max(msize,csize);
        }else if(umap[input[i]] >1){
            while(umap[input[i]] != 1){
                csize--;
                umap[input[i-csize]]--;
                if(umap[input[i-csize]]==0){
                    umap.erase(input[i-csize]);
                }
            }
        }
    }
    return msize;
    
}
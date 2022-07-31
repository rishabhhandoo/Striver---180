#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    
    unordered_map<int,int> umap;
    
    for(int i=0;i<n;i++)
    {
        umap[arr[i]]++;
    }
    int csize=1;
    int modif=1;
    int msize=1;
    for(int i=0;i<n;i++)
    {
        
        if(umap.find(arr[i] -1) == umap.end() ){
            csize=1;
            modif=1;
         while( umap[arr[i]+modif]>0 ){
//                 cout<<" value of modif case 1 "<<umap[arr[i]+modif]<<" value of i"<<i<<endl;
                csize++;
                modif++;
            }
        }
        
//             msize=max(msize,csize);
//             csize=1;
//             modif=1;
//             while( umap[arr[i]-modif]>0 ){
// //                 cout<<" value of modif case -1 "<<umap[arr[i]-modif]<<" value of i"<<i<<endl;
//                 csize++;
//                 modif++;
//             }
        
            msize=max(msize,csize);
    }
    return msize;
}
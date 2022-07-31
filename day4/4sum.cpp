#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    int first=0;
    int second=1;
    int third=2;
    int fourth=n-1;
    string ans;
    
    sort(arr.begin(),arr.end());
    
    for(;first<=n-4;first++)
    {
        second=first+1;
        for(;second<=n-3;second++)
        {
            third=second+1;
            fourth=n-1;
            
            while(third<fourth){
//                 cout<<"one = "<<first<<" second = "<<second<<" third = "<<third<<" fourth = "<<fourth<<endl;
                if(arr[third] + arr[fourth] +arr[second] + arr[first] == target){
                    return "Yes";
                    break;
                }else if(arr[third] + arr[fourth] +arr[second] + arr[first] < target ){
                    third++;
                }else{
                    fourth--;
                }
            }
        }
    }
    return "No";
}

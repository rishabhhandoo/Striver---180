#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	int slow=0;
    int fast=0;
    
    while(slow<n && fast < n){
        fast = arr[arr[fast]];
        slow = arr[slow];
//         cout<<"fast "<<fast<<" slow "<<slow<<endl;
        if(arr[slow] == arr[fast])    break;
    }
    fast =0;
//     slow=arr[slow];
    
    while(arr[slow]!=arr[fast]){
        fast=arr[fast];
        slow=arr[slow];
    }
    return arr[fast];
}

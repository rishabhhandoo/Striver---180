#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	//for first equation
    
    int summ = (n )* (n+1)/2; 
    int sq_summ = (n)*(n+1)*(2*(n) + 1)/6;
    int arr_sum=0;
    int arr_sq_summ =0;
    
    for(int i=0;i<n;i++)
    {
        arr_sum += arr[i];
        arr_sq_summ += arr[i]*arr[i];
    }
    
    int eq1 = (summ - arr_sum);
    int eq2 =  sq_summ - arr_sq_summ;
    
    int eq2f=eq2/eq1;
    int a = abs((float)eq2f/2 + (float)eq1 /2);
    int b = abs(eq1 - a);
    
    return {a,b};
    
	
}

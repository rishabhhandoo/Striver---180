double findNthRootOfM(int n, int m) {
	
    double l =1;
    double r =m;
    double prevmid=0;
    
//         const double multiplier = pow(10.0, 7);
    
    //saving prev mid and abhi wala then seeing if first 6 values are same
    while(l<=r)
    {
        double mid = l + (r-l)/2;
//         mid = ceil(mid * multiplier) / multiplier;
//         cout<<l<<" "<<mid<<" "<<r<<endl;
        if(prevmid == mid )
            return mid;
        
        if(pow(mid,n) == m )    
            return mid;
        else if(pow(mid,n) > m)
            r=mid;        
        else
            l=mid;
        
        prevmid=mid;
    }
    
}
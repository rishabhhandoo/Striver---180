class Solution {
public:
    double helper(double x,int n)
    {
        if(n==0)    return 1.0;
        if(n==1)    return x;
        double num = helper(x,n/2);
        if(n%2==0)  return num*num;
        else    return x*num*num;
    }

    double myPow(double x, int n) {
        if(x==1)    return 1;
        bool flag=false;
        
        if(n<0)
        {
            flag=true;
            n=abs(n);
        }

        double ans = helper(x,n);
        if(flag)
        {
            return 1/ans;
        }
        return ans;
    }
};
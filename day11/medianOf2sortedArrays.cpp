
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() <  nums1.size()) return findMedianSortedArrays(nums2,nums1);
        int n1=nums1.size();
        int n2=nums2.size();
        //len can be odd or even
        int left_len = (n1+n2+1)/2;
                
        int low=0;
        int high=n1;
        cout<<"start of a new test case________"<<n1+n2<<endl;
        // high = (n1<=left_len)? n1 : left_len;
        while(low<=high)
        {
            cout<<"low "<<low<<" high "<<high<<endl;
            int cut1 = (low+high)/2;
            int cut2 =  left_len-cut1;
            
            int l1= (cut1>0)? nums1[cut1-1] : INT_MIN;
            int l2= (cut2>0)? nums2[cut2-1] : INT_MIN;
            
            int r1= (cut1<n1)? nums1[cut1] : INT_MAX;
            int r2= (cut2<n2)? nums2[cut2] : INT_MAX;

            cout<<l1<<" "<<r1<<endl;
            cout<<l2<<" "<<r2<<endl;
            
            if(l1>r2)
            {
                cout<<"l1>r2"<<endl;
                high=cut1-1;
            }else if(l2>r1)
            {
                cout<<"l2>r1"<<endl;
                low=cut1+1;
            }else{
                if( (n1+n2)%2 == 1)
                {
                    return max(l1,l2);
                }else{
                    double ans = (double)(max(l1,l2) + min(r1,r2)) / 2.0;
                    return ans;
                }
            }
        }
        return 0.0;
    }
};
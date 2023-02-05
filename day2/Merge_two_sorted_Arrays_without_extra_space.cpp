class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s=m+n-1;
        int i=m-1;
        int j=n-1;
        if(m==0)    nums1=nums2;
        while(j>=0 && i>=0)
        {
            if(nums2[j]>=nums1[i])
            {
                nums1[s]=nums2[j];
                j--;
                s--;
            }else{
                nums1[s]=nums1[i];
                i--;
                s--;
            }
        }
        while(j>=0)
        {
            nums1[s--]=nums2[j--];
        }
    }
};
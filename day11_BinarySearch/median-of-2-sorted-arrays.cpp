#include<bits/stdc++.h>
class Solution {
public:
//best solution
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        if(n2 < n1) return findMedianSortedArrays(nums2, nums1);
        
        int low=0, high=n1;
        int medianPos = (n1+n2+1)/2;
        int l1,l2,r1,r2;
        while(low<=high) {
            int cut1 = (low+high)/2;
            int cut2 = medianPos-cut1;
            l1 = (cut1==0)? INT_MIN : nums1[cut1-1];
            l2 = (cut2==0)? INT_MIN : nums2[cut2-1];
            r1 = (cut1==n1)?INT_MAX : nums1[cut1];
            r2 = (cut2==n2)?INT_MAX : nums2[cut2];
            
            if(l1<=r2 && l2<=r1) {
                if((n1+n2)%2 == 0) return (max(l1,l2) + min(r1,r2))/2.0;
                else return max(l1,l2);
            }
            else if(l1>r2) {
                high = cut1-1;
            }
            else {
                low=cut1+1;
            }
        }
        return 0.0;
    }
};

//sub optimal solution
double median(vector<int> a, vector<int> b)
{
    if((a.size()+b.size())%2 ==1) {
        int ans;
        int k=(a.size()+b.size()+1)/2;
        int i=0, j=0;
        while(k){
            if(i<a.size() && j<b.size()) {
                if(a[i]<=b[j]) {
                    ans=a[i];
                    i++;
                }
                else {
                    ans=b[j];
                    j++;
                }
            }
            else if(i<a.size()) {
                ans=a[i];
                i++;
            }
            else if(j<b.size()) {
                ans=b[j];
                j++;
            }
            
            k--;
        }
        return ans;
    }
    else {
        int ans1;
        int ans2=0;
        int k=(a.size()+b.size()+2)/2;
        int i=0, j=0;
        while(k){
            ans1=ans2;
            if(i<a.size() && j<b.size()) {
                if(a[i]<=b[j]) {
                    ans2=a[i];
                    i++;
                }
                else {
                    ans2=b[j];
                    j++;
                }
            }
            else if(i<a.size()) {
                ans2=a[i];
                i++;
            }
            else if(j<b.size()) {
                ans2=b[j];
                j++;
            }
            
            k--;
        }
        return (double) (ans1 + ans2)/2;
    }
}

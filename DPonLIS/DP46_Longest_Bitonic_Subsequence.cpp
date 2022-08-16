#include<bits/stdc++.h>
//using of Print LIS algo
//arr[] = { 1,11, 2,10, 4, 5, 2, 1}
//dp1[] = { 1, 2, 2, 3, 3, 4, 2, 1} --->
//dp2[] = { 1, 5, 2, 4, 3, 3, 2, 1} <---
//dp[i] = { 1, 6, 3, 6, 5, 6, 3, 1}
//here dp[i] represents the Longest Bitonic 
//Subsequence where i the peak
int longestBitonicSequence(vector<int>& arr, int n) {
    vector<int> dp1(n,1);
    vector<int> dp2(n,1);
    
    for(int i=0; i<n; i++) {
        for(int prev=0; prev<i; prev++) {
            if(arr[prev]<arr[i] && dp1[i]<1+dp1[prev]) {
                dp1[i] = 1+dp1[prev];
            }
        }
    }
    
    for(int i=n-1; i>=0; i--) {
        for(int prev=n-1; prev>i; prev--) {
            if(arr[prev]<arr[i] && dp2[i]<1+dp2[prev]) {
                dp2[i] = 1+dp2[prev];
            }
        }
    }
    
    int ans=0;
    for(int i=0; i<n; i++) {
        ans= max(ans, dp1[i]+dp2[i]-1);
    }
    return ans;
} 
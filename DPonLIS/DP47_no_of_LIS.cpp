#include<bits/stdc++.h>

//if you need to count no of
//longest or shortest then follow this
//this is also used in no of shortest paths
//from given source to destination in graph
// if(dp[i]<1+dp[prev]) {
//     dp[i] = 1+dp[prev];
//     cnt[i] = cnt[prev];
// }
// else if(dp[i] == 1+dp[prev]) {
//     cnt[i] += cnt[prev];
// }

int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n,1);
    vector<int> cnt(n,1);
    
    int len=0;
    for(int i=0; i<n; i++) {
        for(int prev=0; prev<i; prev++) {
            if(arr[prev]<arr[i]) {
                if(dp[i]<1+dp[prev]) {
                    dp[i] = 1+dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if(dp[i] == 1+dp[prev]) {
                    cnt[i] += cnt[prev];
                }
            }
        }
        if(len < dp[i]) {
            len = dp[i];
        }
    }
    
    //we add up counts of all LIS with 
    //length==len which max len
    //because they are alse
    int count=0;          
    for(int i=0; i<n; i++) {
        if(dp[i] == len) count += cnt[i];
    }
    
    return count;
}
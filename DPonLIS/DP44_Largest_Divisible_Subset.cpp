#include<bits/stdc++.h>
//here you need to return the subset i.e.
//you have to print a variation of LIS
//so use the algo of printing LIS
vector<int> divisibleSet(vector<int> &arr){
    int n = arr.size();
    //if we sort the array we can relate this to LIS
    //and we want subset so the order odesn't matter
    sort(arr.begin(), arr.end());
    
    vector<int> dp(n,1);
    vector<int> prev_map(n,-1);
    
    int len = 0;
    int last;
    for(int i=0;i<n; i++) {
        for(int prev=0; prev<i; prev++) {
            
            if( arr[i]%arr[prev]==0 && dp[i] < 1+dp[prev]) {
                dp[i] = 1+dp[prev];
                prev_map[i] = prev;
            }
            
        }
        if(len < dp[i]) {
            len = dp[i];
            last = i;
        }
    }
    
    vector<int> ans(len);
    while(last != -1) {
        ans[--len] = arr[last];
        last = prev_map[last];
    }
    
    return ans;
}
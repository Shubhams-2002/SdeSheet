#include<bits/stdc++.h>
bool isPre(string prev, string suc) {
    if(1+prev.size() != suc.size()) {
        return false;
    }
    else {
        int i=0, j=0, count=0;
        while( i<prev.size() && j<suc.size() ) {
            if( prev[i]==suc[j] ) {
                i++;
                j++;
            }
            else{
                j++;
                count++;
                if(count>1) return false;
            }
        }
        return true;
    }
}
bool comp(string a, string b) {
    return (a.size() < b.size());
}
int longestStrChain(vector<string> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), comp);
    vector<int> dp(n,1);
    
    int len = 0;
    int last;
    for(int i=0;i<n; i++) {
        for(int prev=0; prev<i; prev++) {
            
            if( isPre(arr[prev], arr[i]) && dp[i] < 1+dp[prev]) {
                dp[i] = 1+dp[prev];
            }
            
        }
        if(len < dp[i]) {
            len = dp[i];
        }
    }
    
    return len;
}
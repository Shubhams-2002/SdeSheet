#include<bits/stdc++.h>
bool isPallindrome(string s, int start, int end) {
        while(start<=end) {
            if(s[start++]!=s[end--]) return false;
        }
        return true;
}
//memoization
int f(int i, int n, string str, vector<int> &dp) {
    if(i==n) return 0;
    if(dp[i] != -1) return dp[i];
    
    int mini = 1e9;
    
    for(int j=i; j<n; j++) {
        if( isPallindrome(str, i, j) ) {
            int num = 1 + f(j+1, n, str, dp);
            mini = min( mini, num );
        }
    }
    
    return dp[i] = mini;
}
int palindromePartitioning1(string str) {
    int n = str.length();
    vector<int> dp(n, -1);
    return f(0,n,str,dp)-1;
}
//tabulation
int palindromePartitioning(string str) {
    int n = str.length();
    vector<int> dp(n+1, 0);
    
    for(int i=n-1; i>=0; i--) {
        int mini = 1e9;
        for(int j=i; j<n; j++) {
            if( isPallindrome(str, i, j) ) {
                int num = 1 + dp[j+1];
                mini = min( mini, num );
            }
        }

        dp[i] = mini;
    }
    return dp[0]-1;
}
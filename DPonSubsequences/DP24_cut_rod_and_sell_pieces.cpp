#include<bits/stdc++.h>

//memoization
int f(int i, int len, vector<int> &price, vector< vector<int> > &dp) {
    if(i==1) {
        return len*price[0];
    }
    if( dp[i][len] != -1 ) return dp[i][len];
    
    int noCut = f(i-1, len, price, dp);
    int cut = INT_MIN;
    if(i <= len ) cut = price[i-1] + f(i, len-i, price, dp);
    
    return dp[i][len] = max(cut, noCut);
}
int cutRod1(vector<int> &price, int n)
{
    vector< vector<int> > dp(n+1, vector<int>(n+1, -1) );
    return f(n, n, price, dp);
}

//tabulation
int cutRod2(vector<int> &price, int n)
{
    vector< vector<int> > dp(n+1, vector<int>(n+1, -1) );
    
    for(int len=0; len<=n; len++) dp[1][len] = len*price[0];
    
    for(int i=2; i<=n; i++) {
        for(int len=0; len<=n; len++) {
            int noCut = dp[i-1][len];
            int cut = INT_MIN;
            if(i <= len ) cut = price[i-1] + dp[i][len-i];

            dp[i][len] = max(cut, noCut);
        }
    }
    
    return dp[n][n];
}

//space optimization
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n+1, -1);
    vector<int> curr(n+1, -1);
    
    for(int len=0; len<=n; len++) prev[len] = len*price[0];
    
    for(int i=2; i<=n; i++) {
        for(int len=0; len<=n; len++) {
            int noCut = prev[len];
            int cut = INT_MIN;
            if(i <= len ) cut = price[i-1] + curr[len-i];

            curr[len] = max(cut, noCut);
        }
        prev = curr;
    }
    
    return prev[n];
}
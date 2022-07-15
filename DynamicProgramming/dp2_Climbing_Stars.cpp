#include<bits/stdc++.h>
long long int f(long long int i, vector<long long int>& dp) {
    if(i==0) return dp[0] = 1;
    
    if(dp[i]!=-1) return dp[i];
    
    long long int fs = f(i-1, dp);
    long long int ss = 0;
    if(i>1) ss = f(i-2, dp);
    
    return dp[i] = fs+ss;
}
int countDistinctWayToClimbStair1(long long nStairs)
{
    vector<long long int> dp(nStairs+1, -1);
    dp[0] = 1;
    for(int i=1; i<=nStairs; i++) {
        long long int fs = dp[i-1];
        long long int ss = 0;
        if(i>1) ss = dp[i-2];

        dp[i] = fs+ss;
    }
    
    return dp[nStairs];
    //return f(nStairs, dp);
}
int countDistinctWayToClimbStair(long long nStairs)
{
    int curr, prev2 = 1, prev1 = 1;
    for(int i=2; i<=nStairs; i++) {
        curr = prev1 + prev2;
        
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
    //return f(nStairs, dp);
}

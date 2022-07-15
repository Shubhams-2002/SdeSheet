#include<bits/stdc++.h>
//memoization
int f(int i, vector<int> &heights, vector<int>& dp) {
    if(i==0) return dp[0] = 0;
    if(dp[i]!=-1) return dp[i];
    
    int fs = f(i-1, heights, dp) + abs(heights[i] - heights[i-1]);
    int ss = INT_MAX;
    if(i>1) ss = f(i-2 ,heights, dp) + abs(heights[i] - heights[i-2]);
    
    return dp[i] = min(fs, ss);
}
//tabulation
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    for(int i=1; i<n; i++) {
        int fs = dp[i-1] + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i>1) ss = dp[i-2] + abs(heights[i] - heights[i-2]);

        dp[i] = min(fs, ss);
    }
    return dp[n-1];
    //return f(n-1, heights, dp);
}
//space optimized
int frogJump1(int n, vector<int> &heights)
{
    if(n==1) return 0;
    int prev2=0;
    int prev1=heights[1] - heights[0];
    int curr;
    for(int i=2; i<n; i++) {
        int fs = prev1 + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i>1) ss = prev2 + abs(heights[i] - heights[i-2]);

        curr = min(fs, ss);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
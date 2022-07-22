#include<bits/stdc++.h>
//memoization
int f(int i, int prev, int n, vector<vector<int>> &points, 
      vector<vector<int>> &dp) {
    
    if(i==n) return 0;
    if(dp[i][prev] != -1) return dp[i][prev];
    
    int maxi = INT_MIN;
    for(int j=0; j<3; j++) {
        if(j!=prev) {
            maxi = max( maxi, points[i][j] + f(i+1, j, n, points, dp) );
        }
    }
    return dp[i][prev] = maxi;
}

//tabulation
int ninjaTraining1(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n+1, vector<int>(4, -1));
    //return f(0, 3, n, points, dp);
    //if no activity is done previously you can call previous activity as 3, rather than -1

    for(int j=0; j<4; j++) dp[n][j] = 0;
    
    for(int i=n-1; i>=0; i--) {
        for(int prev=3; prev>=0; prev--) {
            
            int maxi = INT_MIN;
            for(int j=0; j<3; j++) {
                if(j!=prev) {
                    maxi = max( maxi, points[i][j] + dp[i+1][j] );
                }
            }
            dp[i][prev] = maxi;
            
        }
    }
    
    return dp[0][3];
}

//space optimized
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> next(4, 0); 
    vector<int> curr(4, 0); 
    
    for(int i=n-1; i>=0; i--) {
        for(int prev=3; prev>=0; prev--) {
            
            int maxi = INT_MIN;
            for(int j=0; j<3; j++) {
                if(j!=prev) {
                    maxi = max( maxi, points[i][j] + next[j] );
                }
            }
            curr[prev] = maxi;
        }
        next = curr;
    }
    
    return next[3];
}
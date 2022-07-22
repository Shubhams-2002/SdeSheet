#include<bits/stdc++.h> 

//memoization
int f(int i, int j, vector< vector<int> > &dp) {
    if(i==0 || j==0) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    
    return dp[i][j] = f(i-1, j, dp) + f(i, j-1, dp);
}

//tabulation
int uniquePaths1(int m, int n) {
    vector< vector<int> > dp(m, vector<int>(n,-1) );
    //return f(m-1, n-1, dp);
    
    for(int i=0; i<m; i++) dp[i][0]=1;
    for(int j=1; j<n; j++) dp[0][j]=1;
    
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[m-1][n-1];
}

//space optimizied
int uniquePaths(int m, int n) {
    vector<int> prev(n, 1);//first row i.e. i==0, hence initializwd with 1
    vector<int> curr(n, 0);
    
    for(int i=1; i<m; i++) {
        curr[0] = 1;
        for(int j=1; j<n; j++) {
            curr[j] = prev[j] + curr[j-1];
        }
        prev = curr;
    }
    
    return prev[n-1];
}

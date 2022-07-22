#include<bits/stdc++.h>

//refer strivers solution also 
//it is shorter and simpler as it doesn't need for loop
//https://takeuforward.org/data-structure/minimum-path-sum-in-triangular-grid-dp-11/

//memoization
int f(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
    if(i==0 && j==0) {
        return triangle[i][j];
    }
    if(dp[i][j] != -1) return dp[i][j];
    
    int up=INT_MAX, upperLeft=INT_MAX;
    if(j<i) up = triangle[i][j] + f(i-1, j, triangle, dp);
    if(j>0) upperLeft = triangle[i][j] + f(i-1, j-1, triangle, dp);
    
    return dp[i][j] = min(up, upperLeft);
}
int minimumPathSum1(vector<vector<int>>& triangle, int n) {
    vector< vector<int> > dp(n, vector<int>(n,-1) );
    
    int ans = INT_MAX;
    for(int j=0; j<n; j++) {
        ans = min(ans, f(n-1, j, triangle, dp));
    }
    
    return ans;
}

//tabulation
int minimumPathSum2(vector<vector<int>>& triangle, int n) {
    vector< vector<int> > dp(n, vector<int>(n,-1) );
    
    dp[0][0] = triangle[0][0];
    for(int i=1; i<n; i++) {
        for(int j=0; j<=i; j++) {
            int up=INT_MAX, upperLeft=INT_MAX;
            if(j<i) up = triangle[i][j] + dp[i-1][j];
            if(j>0) upperLeft = triangle[i][j] + dp[i-1][j-1];

            dp[i][j] = min(up, upperLeft);
        }
    }
    
    int ans = INT_MAX;
    for(int j=0; j<n; j++) {
        ans = min(ans, dp[n-1][j]);
    }
    
    return ans;
}

//space optimized
int minimumPathSum(vector<vector<int>>& triangle, int n) {
    vector<int> prev(n,-1);
    vector<int> curr(n,-1);
    
    prev[0] = triangle[0][0];
    for(int i=1; i<n; i++) {
        for(int j=0; j<=i; j++) {
            int up=INT_MAX, upperLeft=INT_MAX;
            if(j<i) up = triangle[i][j] + prev[j];
            if(j>0) upperLeft = triangle[i][j] + prev[j-1];

            curr[j] = min(up, upperLeft);
        }
        prev = curr;
    }
    
    int ans = INT_MAX;
    for(int j=0; j<n; j++) {
        ans = min(ans, prev[j]);
    }
    
    return ans;
}
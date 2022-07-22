#include<bits/stdc++.h>

//memoization
int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if(i==0 && j==0) {
        return grid[i][j];
    }
    if(dp[i][j] != -1) return dp[i][j];
    
    int up=INT_MAX, left=INT_MAX;
    if(i>0) up = grid[i][j] + f(i-1, j, grid, dp);
    if(j>0) left = grid[i][j] + f(i, j-1, grid, dp);
    
    return dp[i][j] = min(up, left);
}

//tabulation
int minSumPath1(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1) );
    //return f(n-1, m-1, grid, dp);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i==0 && j==0) {
                dp[i][j] = grid[i][j];
                continue;
            }

            int up=INT_MAX, left=INT_MAX;
            if(i>0) up = grid[i][j] + dp[i-1][j];
            if(j>0) left = grid[i][j] + dp[i][j-1];

            dp[i][j] = min(up, left);
        }
    }
    
    return dp[n-1][m-1];
}

//space optimized
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m,-1);
    vector<int> curr(m,-1);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i==0 && j==0) {
                curr[j] = grid[i][j];
                continue;
            }

            int up=INT_MAX, left=INT_MAX;
            if(i>0) up = grid[i][j] + prev[j];
            if(j>0) left = grid[i][j] + curr[j-1];

            curr[j] = min(up, left);
        }
        prev = curr;
    }
    
    return prev[m-1];
}
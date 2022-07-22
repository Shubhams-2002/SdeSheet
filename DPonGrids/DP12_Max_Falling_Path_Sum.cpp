#include<bits/stdc++.h>

//memoization
int f(int i, int j, int n, int m, vector<vector<int>> &grid, 
      vector<vector<int>> &dp) {
    if(j<0 || j>=m) return -1e9; //biggest number in input is 1e4
    if(i==0) {
        return grid[0][j];
    }
    if(dp[i][j] != -1) return dp[i][j];
    
    int up = grid[i][j] + f(i-1, j, n, m, grid, dp);
    int upperLeft = grid[i][j] + f(i-1, j-1, n, m, grid, dp);
    int upperRight= grid[i][j] + f(i-1, j+1, n, m, grid, dp);
    
    return dp[i][j] = max(up, max(upperLeft, upperRight) );
}
int getMaxPathSum1(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1) );
    
    int ans = INT_MIN;
    for(int j=0; j<m; j++) {
        ans = max(ans, f(n-1, j, n, m, matrix, dp));
    }
    
    return ans;
}

//tabulation
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1) );
    
    for(int j=0; j<m; j++) dp[0][j] = matrix[0][j];
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            int upperLeft=INT_MIN, upperRight=INT_MIN;
            
            int up = matrix[i][j] + dp[i-1][j];
            if(j>0) upperLeft = matrix[i][j] + dp[i-1][j-1];
            if(j<m-1) upperRight= matrix[i][j] + dp[i-1][j+1];

            dp[i][j] = max(up, max(upperLeft, upperRight) );
        }
    }
    
    int ans = INT_MIN;
    for(int j=0; j<m; j++) {
        ans = max(ans, dp[n-1][j]);
    }
    
    return ans;
}
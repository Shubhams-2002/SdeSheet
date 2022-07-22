#include<bits/stdc++.h> 

//memoization
int f(int i, int j,  vector< vector< int> > &mat, 
                vector< vector<int> > &dp) {
    if(i>=0 && j>=0 && mat[i][j]==-1) return 0; 
    if(i==0 && j == 0)
        return 1;
    if(i<0 || j<0)
        return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int up = f(i-1, j, mat, dp);
    int left = f(i, j-1, mat, dp);
    
    int mod = 1e9 + 7;
    return dp[i][j] = (up + left) % mod;
}
int mazeObstacles1(int n, int m, vector< vector< int> > &mat) {
    vector< vector<int> > dp(n, vector<int>(m,-1) );
    return f(n-1, m-1, mat, dp);
}

//tabulation
int mazeObstacles2(int n, int m, vector< vector< int> > &mat) {
    vector< vector<int> > dp(n, vector<int>(m,-1) );
    int mod = 1e9 + 7;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i>=0 && j>=0 && mat[i][j]==-1) {
                dp[i][j] = 0;
                continue;
            } 
            if(i==0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }

            int up = (i>0)? dp[i-1][j]:0;
            int left = (j>0)? dp[i][j-1]:0;

            dp[i][j] = (up + left) % mod;
        }
    }
    
    return dp[n-1][m-1];
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<int> prev(m, 0);
    vector<int> curr(m,0);
    int mod = 1e9 + 7;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i>=0 && j>=0 && mat[i][j]==-1) {
                curr[j] = 0;
                continue;
            } 
            if(i==0 && j == 0) {
                curr[j] = 1;
                continue;
            }

            int up = (i>0)? prev[j]:0;
            int left = (j>0)? curr[j-1]:0;

            curr[j] = (up + left) % mod;
        }
        prev = curr;
    }
    
    return prev[m-1];
}
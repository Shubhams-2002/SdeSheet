#include<bits/stdc++.h>
//memoization
int f(int i, int j, vector<int>& a, vector<vector<int>> &dp) {
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int maxi = -1e9;
    for(int k=i; k<=j; k++) {
        int ans = a[i-1]*a[k]*a[j+1] + f(i,k-1,a,dp) + f(k+1,j,a,dp);
        maxi = max( maxi, ans);
    }
    
    return dp[i][j] = maxi;
}
int maxCoins1(vector<int>& a)
{
    a.insert(a.begin(), 1);
    a.push_back(1);
    
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n, -1) );
    return f(1, n-2, a, dp);
}

//tabulation
int maxCoins(vector<int>& a)
{
    a.insert(a.begin(), 1);
    a.push_back(1);
    
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n, 0) );
    
    for(int i=n-2; i>0; i--) {
        for(int j=i; j<n; j++) {
            int maxi = -1e9;
            for(int k=i; k<=j; k++) {
                int ans = a[i-1]*a[k]*a[j+1] + f(i,k-1,a,dp) + f(k+1,j,a,dp);
                maxi = max( maxi, ans);
            }

            dp[i][j] = maxi;
        }
    }
    
    return dp[1][n-2];
}
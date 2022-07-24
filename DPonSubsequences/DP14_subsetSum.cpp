#include<bits/stdc++.h>

//memoization
bool f(int i, int k, vector<int> &arr, vector< vector<int> > &dp) {
    if(k==0) return true;
    if(i==0) {
        return (arr[0]==k);
    }
    if(dp[i][k] != -1) return dp[i][k];
    
    bool pick = (arr[i]<=k)? f(i-1, k-arr[i], arr, dp) : false;
    bool notPick = f(i-1, k, arr, dp);
    
    return dp[i][k] = (pick || notPick)? 1 : 0;
}
bool subsetSumToK1(int n, int k, vector<int> &arr) {
    vector< vector<int> > dp(n, vector<int>(k+1, -1) );
    return f(n-1, k, arr, dp);
}

//tabulation
bool subsetSumToK2(int n, int k, vector<int> &arr) {
    vector< vector<bool> > dp(n, vector<bool>(k+1, false) );
    //base cases
    for(int i=0; i<n; i++) {
        dp[i][0] = true;
    }
    if(arr[0] <=k)  dp[0][arr[0]] = true; 
    
    //loops
    for(int i=1; i<n; i++) {
        for(int j=1; j<=k; j++) {
            bool pick = (arr[i]<=j)? dp[i-1][j-arr[i]] : false;
            bool notPick = dp[i-1][j];
            
            dp[i][j] = pick || notPick;
        }
    }
    return dp[n-1][k];
}

//space optimized
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, false);
    vector<bool> curr(k+1, false);
    //base cases
    prev[0] = true;
    if(arr[0] <=k) prev[arr[0]] = true; 
    
    //loops
    for(int i=1; i<n; i++) {
        curr[0] = true; //be careful of this
        for(int j=1; j<=k; j++) {
            bool pick = (arr[i]<=j)? prev[j-arr[i]] : false;
            bool notPick = prev[j];
            
            curr[j] = pick || notPick;
        }
        swap(prev, curr);
    }
    return prev[k];
}
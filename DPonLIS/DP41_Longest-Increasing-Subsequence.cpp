#include<bits/stdc++.h>
//memoization
//10^5 * 10^5 = 10^10 dp matrix can't be made hence we get RunTime Error
//best solution is n*log(n)
int f(int i, int prev, int a[], int n, vector<vector<int>> &dp) {
    if(i==n) {
        return 0;
    }
    if( dp[i][prev+1] != -1 ) return dp[i][prev+1];
    
    int notPick = f(i+1, prev, a, n, dp);
    int pick = 0;
    if(prev==-1 || a[prev]<a[i]) {
        pick = 1 + f(i+1, i, a, n, dp);
    }
    
    return dp[i][prev+1] = max(pick, notPick);
} 
int longestIncreasingSubsequence1(int arr[], int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1) );

    return f(0, -1, arr, n, dp);
}

//tabulation
int longestIncreasingSubsequence2(int arr[], int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0) );

    for(int i=n-1; i>=0; i--) {
        for(int prev=n-1; prev>=-1; prev--) {
            int notPick = dp[i+1][prev+1];
            int pick = 0;
            if(prev==-1 || arr[prev]<arr[i]) {
                pick = 1 + dp[i+1][i+1];
            }

            dp[i][prev+1] = max(pick, notPick);
        }
    }
    return dp[0][0];
}

//space optimization
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0) );
    vector<int> ahead(n+1,0);
    vector<int> curr(n+1,0);
    for(int i=n-1; i>=0; i--) {
        for(int prev=n-1; prev>=-1; prev--) {
            int notPick = ahead[prev+1];
            int pick = 0;
            if(prev==-1 || arr[prev]<arr[i]) {
                pick = 1 + ahead[i+1];
            }

            curr[prev+1] = max(pick, notPick);
        }
        swap(ahead, curr);
    }
    return ahead[0];
}
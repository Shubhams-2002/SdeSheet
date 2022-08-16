#include<bits/stdc++.h>

//memoization
int f(int i, int n, int k, vector<int> &num, vector<int> &dp) {
    if(i==n) return 0;
    if(dp[i] != -1) return dp[i];
    
    int maxEle = num[i];
    int maxi = INT_MIN;
    for(int j=i; j<i+k && j<n; j++) {
        maxEle = max( maxEle, num[j] );
        int total = (j-i+1)*maxEle + f(j+1, n, k, num, dp);
        maxi = max( maxi, total);
    }
    
    return dp[i] = maxi;
}
int maximumSubarray1(vector<int> &num, int k)
{
    int n = num.size();
    vector<int> dp(n, -1);
    return f(0, n, k, num, dp);
}

//tabulation
int maximumSubarray(vector<int> &num, int k)
{
    int n = num.size();
    vector<int> dp(n+1, 0);
    //base case is dp[n]=0, initialized to 0
    for(int i=n-1; i>=0; i--) {
        int maxEle = num[i];
        int maxi = INT_MIN;
        for(int j=i; j<i+k && j<n; j++) {
            maxEle = max( maxEle, num[j] );
            int total = (j-i+1)*maxEle + dp[j+1];
            maxi = max( maxi, total);
        }
        dp[i] = maxi;
    }
    return dp[0];
}
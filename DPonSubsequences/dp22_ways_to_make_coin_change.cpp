#include<bits/stdc++.h>

//memoization
long f(int i, int tar, int* num, vector<vector<long>> &dp) {
    if(i==0) {
        if(tar%num[0] == 0) return 1;
        else return 0;
    }
    if(dp[i][tar] != -1) return dp[i][tar];
    
    long notPick = f(i-1, tar, num, dp);
    long pick = 0;
    if(num[i] <= tar) pick = f(i, tar-num[i], num, dp);
    
    return dp[i][tar] = (notPick + pick);
}
long countWaysToMakeChange1(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, -1) );
    return f(n-1, value, denominations, dp);
}

//tabulation
long countWaysToMakeChange2(int *coins, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, -1) );
    
    for(int tar=0; tar<=value; tar++) {
        if(tar%coins[0] == 0) dp[0][tar] = 1;
        else dp[0][tar] = 0;
    }
    
    for(int i=1; i<n; i++) {
        for(int tar=0; tar<=value; tar++) {
            long notPick = dp[i-1][tar];
            long pick = 0;
            if(coins[i] <= tar) pick = dp[i][ tar-coins[i] ];

            dp[i][tar] = (notPick + pick);
        }
    }
    
    return dp[n-1][value];
}

//space optimization
long countWaysToMakeChange(int *coins, int n, int value)
{
    vector<long> prev(value+1, 0) ;
    vector<long> curr(value+1, 0) ;
    
    for(int tar=0; tar<=value; tar++) {
        if(tar%coins[0] == 0) prev[tar] = 1;
        else prev[tar] = 0;
    }
    
    for(int i=1; i<n; i++) {
        for(int tar=0; tar<=value; tar++) {
            long notPick = prev[tar];
            long pick = 0;
            if(coins[i] <= tar) pick = curr[ tar-coins[i] ];

            curr[tar] = (notPick + pick);
        }
        prev = curr;
    }
    
    return prev[value];
}
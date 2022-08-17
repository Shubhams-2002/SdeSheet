#include<bits/stdc++.h>
//memoization
int f(int i, int buy, int fee, int n, vector<int> &prices, vector<vector<int>>& dp) {
    if(i==n) return 0;
    if(dp[i][buy] != -1) return dp[i][buy];
    
    long profit=0;
    if(buy) {
        profit = max( -prices[i]+f(i+1, 0, fee, n, prices, dp),
                      f(i+1, 1, fee, n, prices, dp) );
    }
    else {
        profit = max( prices[i]+f(i+1, 1, fee, n, prices, dp)-fee,
                      f(i+1, 0, fee, n, prices, dp) );
    }
    
    return dp[i][buy] = profit;
}
int maximumProfit2(int n, int fee, vector<int> &prices) {
    vector<vector<int>> dp( n, vector<int>(2,-1) );
    return f(0, 1, fee, n, prices, dp);
}

//tabulation
int maximumProfit1(int n, int fee, vector<int> &prices) {
    vector<vector<int>> dp( n+1, vector<int>(2,0) );
    dp[n][0] = dp[n][1] = 0;
    
    for(int i=n-1; i>=0; i--) {
        for(int buy=0; buy<=1; buy++) {
            long profit=0;
            if(buy) {
                profit = max(-prices[i]+dp[i+1][0] , dp[i+1][1] );
            }
            else {
                //fee will be dedected after selling
                profit = max( prices[i]+dp[i+1][1]-fee , dp[i+1][0] );
            }
            dp[i][buy] = profit;
        }
    }
    
    return dp[0][1];
}

//space optimization
int maximumProfit(int n, int fee, vector<int> &prices)
{
    vector<long> ahead(2,0), curr(2,0);
    
    for(int i=n-1; i>=0; i--) {
        for(int buy=0; buy<=1; buy++) {
            long profit=0;
            if(buy) {
                profit = max(-prices[i]+ahead[0] , ahead[1] );
            }
            else {
                profit = max( prices[i]+ahead[1]-fee , ahead[0] );
            }
            curr[buy] = profit;
        }
        ahead[0] = curr[0];
        ahead[1] = curr[1];
    }
    
    return ahead[1];
}
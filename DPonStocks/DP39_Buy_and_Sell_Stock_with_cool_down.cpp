#include<bits/stdc++.h>
//memoization
int f(int i, int buy, int n, vector<int> &prices, vector<vector<int>>& dp) {
    if(i>=n) return 0;
    if(dp[i][buy] != -1) return dp[i][buy];
    
    long profit=0;
    if(buy) {
        profit = max( -prices[i]+f(i+1, 0, n, prices, dp),
                      f(i+1, 1, n, prices, dp) );
    }
    else {
        //we have a cool down period of 1 day 
        //so we can't go to next day but
        //we go to i+cooldown_period+1
        profit = max( prices[i]+f(i+2, 1, n, prices, dp),
                      f(i+1, 0, n, prices, dp) );
    }
    
    return dp[i][buy] = profit;
}
int stockProfit1(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp( n, vector<int>(2,-1) );
    return f(0, 1, n, prices, dp);
}

//tabulation
int stockProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp( n+1, vector<int>(2,0) );
    dp[n][0] = dp[n][1] = 0;
    
    for(int i=n-1; i>=0; i--) {
        for(int buy=0; buy<=1; buy++) {
            long profit=0;
            if(buy) {
                profit = max(-prices[i]+dp[i+1][0] , dp[i+1][1] );
            }
            else {
                //we have a cool down period of 1 day 
                //so we can't go to next day but
                //we go to i+cooldown_period+1
                if( i+2>n ) profit = max( prices[i] , dp[i+1][0] );
                //to handle the edge case when i==n-1
                else profit = max( prices[i]+dp[i+2][1] , dp[i+1][0] );
            }
            dp[i][buy] = profit;
        }
    }
    
    return dp[0][1];
}
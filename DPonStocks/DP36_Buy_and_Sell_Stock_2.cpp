//Q. buy and sell any number of times to maximize profit 
//but buy next stock only after selling previously bought

#include<bits/stdc++.h>
//memoization
//buy=1 indicates you can buy the current stock
//for both cases you can buy a stock or not 
// and you can sell a stock or not 
long f(int i, int buy, int n, long *values, vector<vector<long>>& dp) {
    if(i==n) return 0;
    if(dp[i][buy] != -1) return dp[i][buy];
    
    long profit=0;
    if(buy) {
        profit = max( -values[i]+f(i+1, 0, n, values, dp),
                      f(i+1, 1, n, values, dp) );
    }
    else {
        profit = max( values[i]+f(i+1, 1, n, values, dp),
                      f(i+1, 0, n, values, dp) );
    }
    
    return dp[i][buy] = profit;
}
long getMaximumProfit1(long *values, int n)
{
    vector<vector<long>> dp( n, vector<long>(2,-1) );
    return f(0, 1, n, values, dp);
}

//tabulation
long getMaximumProfit2(long *values, int n)
{
    vector<vector<long>> dp( n+1, vector<long>(2,-1) );
    dp[n][0] = dp[n][1] = 0;
    
    for(int i=n-1; i>=0; i--) {
        for(int buy=0; buy<=1; buy++) {
            long profit=0;
            if(buy) {
                profit = max(-values[i]+dp[i+1][0] , dp[i+1][1] );
            }
            else {
                profit = max( values[i]+dp[i+1][1] , dp[i+1][0] );
            }
            dp[i][buy] = profit;
        }
    }
    
    return dp[0][1];
}

//space optimization 
//as you can clearly see we only need (i+1)th to calculate ith
long getMaximumProfit(long *values, int n)
{
    vector<long> ahead(2,0), curr(2,0);
    
    for(int i=n-1; i>=0; i--) {
        for(int buy=0; buy<=1; buy++) {
            long profit=0;
            if(buy) {
                profit = max(-values[i]+ahead[0] , ahead[1] );
            }
            else {
                profit = max( values[i]+ahead[1] , ahead[0] );
            }
            curr[buy] = profit;
        }
        ahead[0] = curr[0];
        ahead[1] = curr[1];
    }
    
    return ahead[1];
}
//here have use 2 arrays of size 2, which is equivalent of 4 variables
//you can also show 4 variables like 
//aheadBuy, aheadNotBuy, currBuy, currNotBuy
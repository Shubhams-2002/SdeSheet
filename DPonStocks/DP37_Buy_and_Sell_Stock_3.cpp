//Q. buy and sell only 2 times to maximize profit 
//but buy next stock only after selling previously bought
//buying and selling is 1 transaction, at most 2 transactions

#include<bits/stdc++.h>
//memoization
int f(int i, int cap, int buy, vector<int>& prices, int n, 
     vector<vector<vector<int>>>& dp) {
    if(cap==0) return 0;
    if(i==n) return 0;
    if(dp[i][cap][buy] != -1) return dp[i][cap][buy];
    
    long profit=0;
    if(buy) {
        profit = max( -prices[i]+f(i+1, cap, 0, prices, n, dp),
                      f(i+1, cap, 1, prices, n, dp) );
    }
    else {
        //after selling we have completed 1 transaction
        //hence we reduce capacity by 1
        profit = max( prices[i]+f(i+1, cap-1, 1, prices, n, dp),
                      f(i+1, cap, 0, prices, n, dp) );
    }
    
    return dp[i][cap][buy] = profit;
}
int maxProfit1(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(3,vector<int>(2,-1)));
    return f(0, 2, 1, prices, n, dp);
}//i=0->n; cap=2->0; 

//tabulation
//i=n->0; cap=0->2; we move from base case to bigger 
int maxProfit2(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3,vector<int>(2,0)));
    
    for(int i=n-1; i>=0; i--) {
        for(int cap=1; cap<=2; cap++) {
            for(int buy=0; buy<=1; buy++) {
                int profit=0;
                if(buy) {
                    profit = max(-prices[i]+dp[i+1][cap][0] , dp[i+1][cap][1] );
                }
                else {
                    profit = max( prices[i]+dp[i+1][cap-1][1] , dp[i+1][cap][0] );
                }
                dp[i][cap][buy] = profit;
            }
        }
    }
    
    return dp[0][2][1];
}

//sapce optimization
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<int>> ahead(3,vector<int>(2,0));
    vector<vector<int>> curr(3,vector<int>(2,0));
    
    for(int i=n-1; i>=0; i--) {
        for(int cap=1; cap<=2; cap++) {
            for(int buy=0; buy<=1; buy++) {
                int profit=0;
                if(buy) {
                    profit = max(-prices[i]+ahead[cap][0] , ahead[cap][1] );
                }
                else {
                    profit = max( prices[i]+ahead[cap-1][1] , ahead[cap][0] );
                }
                curr[cap][buy] = profit;
            }
        }
        swap(curr , ahead);
    }
    
    return ahead[2][1];
}
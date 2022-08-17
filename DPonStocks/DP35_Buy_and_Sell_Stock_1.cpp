//Q. buy and sell only once to maximize profit 

#include <bits/stdc++.h> 
//if we are selling an ith stock and we want to maximize 
//the profit, then we should have bought the minimum of 0...i-1
//using a minPrice variable we will have minimum of 0...i-1
//dp is remembering the past
int maximumProfit(vector<int> &prices)
{
    int n = prices.size();
    int minPrice = prices[0];
    int maxProfit = 0;
    
    //you can't sell on day 0
    for(int i=1; i<n; i++) {
        maxProfit = max( maxProfit, prices[i]-minPrice );
        minPrice = min( minPrice, prices[i] );
    }
    
    return maxProfit;
}
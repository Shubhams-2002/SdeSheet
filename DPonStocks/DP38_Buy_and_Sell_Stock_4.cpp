//Q. buy and sell only 2 times to maximize profit 
//but buy next stock only after selling previously bought
//buying and selling is 1 transaction, at most k transactions

#include<bits/stdc++.h>
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<int>> ahead(k+1,vector<int>(2,0));
    vector<vector<int>> curr(k+1,vector<int>(2,0));
    
    for(int i=n-1; i>=0; i--) {
        for(int cap=1; cap<=k; cap++) {
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
    
    return ahead[k][1];
}

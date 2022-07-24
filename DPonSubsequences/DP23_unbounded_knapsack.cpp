#include<bits/stdc++.h>

//memoization
int f(int i, int w, vector<int>& weight, vector<int>& value, 
      vector< vector<int> > &dp){
    if(i==0){
        //try to take as many as possibile
        int maxItems = w/weight[0];
        return maxItems*value[0];
    }
    if(dp[i][w] != -1) return dp[i][w];
    
    int notPick = f(i-1, w, weight, value, dp);
    int pick = INT_MIN;
    if(weight[i]<=w) 
        pick = value[i] + f(i, w-weight[i], weight, value, dp);
    
    return dp[i][w] = max(pick, notPick);
}
int unboundedKnapsack1(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector< vector<int> > dp(n, vector<int> (w+1, -1) );
    return f(n-1, w, weight, profit, dp);
}

//tabulation
int unboundedKnapsack2(int n, int maxWeight, vector<int> &value, vector<int> &weight)
{
    vector< vector<int> > dp(n, vector<int> (maxWeight+1, 0) );
    
    for(int w=0; w<=maxWeight; w++) {
        int maxItems = w/weight[0];
        dp[0][w] = maxItems*value[0];
    }
    
    for(int i=1; i<n; i++) {
        for(int w=0; w<=maxWeight; w++) {
            int notPick = dp[ i-1 ][ w ];
            int pick = INT_MIN;
            if(weight[i]<=w) 
                pick = value[i] + dp[ i ][ w-weight[i] ];

            dp[i][w] = max(pick, notPick);
        }
    }
    
    return dp[n-1][maxWeight];
}

//space optimized
int unboundedKnapsack(int n, int maxWeight, vector<int> &value, vector<int> &weight)
{
    vector<int> prev(maxWeight+1, 0);
    vector<int> curr(maxWeight+1, 0);
    
    for(int w=0; w<=maxWeight; w++) {
        int maxItems = w/weight[0];
        prev[w] = maxItems*value[0];
    }
    
    for(int i=1; i<n; i++) {
        for(int w=0; w<=maxWeight; w++) {
            int notPick = prev[ w ];
            int pick = INT_MIN;
            if(weight[i]<=w) 
                pick = value[i] + curr[ w-weight[i] ];

            curr[w] = max(pick, notPick);
        }
        prev = curr;
    }
    
    return prev[maxWeight];
}
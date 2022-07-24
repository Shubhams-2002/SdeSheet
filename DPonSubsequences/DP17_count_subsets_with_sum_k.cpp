#include<bits/stdc++.h>

//memoization
int f(int i, int tar, vector<int> &num, vector<vector<int>> &dp) {
    if(i==0) {
        if(num[0]==0 && tar==0) {
            return 2;
        }
        else if(num[0]==tar || tar==0) {
            return 1;
        }
        else return 0;
    }
    if(dp[i][tar]!=-1) return dp[i][tar];
    
    int pick = (tar>=num[i])? f(i-1, tar-num[i], num, dp) : 0;
    int notPick = f(i-1, tar, num, dp);
    
    return dp[i][tar] = pick + notPick;
}
int findWays1(vector<int> &num, int tar)
{
    int n = num.size();
    vector< vector<int> > dp(n, vector<int>(tar+1,-1) );
    return f(n-1, tar, num, dp);
}

//tabulation
int findWays2(vector<int> &num, int tar)
{
    int n = num.size();
    vector< vector<int> > dp(n, vector<int>(tar+1,0) );
    
    //base cases
    if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(num[0] != 0 && num[0]<=tar) dp[0][num[0]] = 1; 
    
    //loops
    for(int i=1; i<n; i++) {
        for(int j=0; j<=tar; j++) {
            int pick = (j>=num[i])? dp[i-1][j-num[i]] : 0;
            int notPick = dp[i-1][j];

            dp[i][j] = pick + notPick;
        }
    }
    
    return dp[n-1][tar];
}

//space optimized
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> prev(tar+1,0);
    vector<int> curr(tar+1,0);
    
    //base cases
    if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
    else prev[0] = 1;  // 1 case - not pick
    
    if(num[0] != 0 && num[0]<=tar) prev[num[0]] = 1; 
    
    //loops
    for(int i=1; i<n; i++) {
        for(int j=0; j<=tar; j++) {
            int pick = (j>=num[i])? prev[j-num[i]] : 0;
            int notPick = prev[j];

            curr[j] = pick + notPick;
        }
        prev = curr;
    }
    
    return prev[tar];
}
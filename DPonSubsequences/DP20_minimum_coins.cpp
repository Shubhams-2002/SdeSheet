#include<bits/stdc++.h>

//memoization
int f(int i, int tar, vector<int> &num, vector<vector<int>> &dp) {
    if(i==0) {
        if(tar%num[0] == 0) return tar/num[0];
        else return 1e9;
    }
    if(dp[i][tar] != -1) return dp[i][tar];
    
    int notPick = f(i-1, tar, num, dp);
    int pick = 1e9;
    if(num[i] <= tar) pick = 1 + f(i, tar-num[i], num, dp);
    
    return dp[i][tar] = min(notPick , pick);
}
int minimumElements1(vector<int> &num, int x)
{
    int n= num.size();
    vector<vector<int>> dp(n, vector<int>(x+1, -1) );
    
    int ans =  f(n-1, x, num, dp);
    //if INT_MAX doesn't work always try 1e9
    if(ans >= 1e9) return -1;
    return ans;
}

//tabulation
int minimumElements2(vector<int> &num, int x)
{
    int n= num.size();
    vector<vector<int>> dp(n, vector<int>(x+1, -1) );
    
    for(int tar=0; tar<=x; tar++) {
        if(tar%num[0] == 0) dp[0][tar] = tar/num[0];
        else dp[0][tar] = 1e9;
    }
    
    for(int i=1; i<n; i++) {
        for(int tar=0; tar<=x; tar++) {
            
            int notPick = dp[i-1][tar];
            int pick = 1e9;
            if(num[i] <= tar) pick = 1 + dp[i][ tar-num[i] ];

            dp[i][tar] = min(notPick , pick);
        }
    }
    
    int ans =  dp[n-1][x];
    //if INT_MAX doesn't work always try 1e9
    if(ans >= 1e9) return -1;
    return ans;
}

//space optimized
int minimumElements3(vector<int> &num, int x)
{
    int n= num.size();
    vector<int> prev(x+1, 0);
    vector<int> curr(x+1, 0);
    
    for(int tar=0; tar<=x; tar++) {
        if(tar%num[0] == 0) prev[tar] = tar/num[0];
        else prev[tar] = 1e9;
    }
    
    for(int i=1; i<n; i++) {
        for(int tar=0; tar<=x; tar++) {
            
            int notPick = prev[tar];
            int pick = 1e9;
            if(num[i] <= tar) pick = 1 + prev[ tar-num[i] ];

            curr[tar] = min(notPick , pick);
        }
        prev = curr;
    }
    
    int ans =  prev[x];
    //if INT_MAX doesn't work always try 1e9
    if(ans >= 1e9) return -1;
    return ans;
}
int minimumElements(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<int> prev(T+1,0), cur(T+1,0);
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            prev[i] = i/arr[0];
        else prev[i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + prev[target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + cur[target - arr[ind]];
                
             cur[target] = min(notTake, take);
        }
        prev = cur;
    }
    
    int ans = prev[T];
    if(ans >=1e9) return -1;
    return ans;
}
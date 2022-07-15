#include<bits/stdc++.h>
//memoization
int f(int i, vector<int> &nums, vector<int> &dp) {
    if(i==0) return dp[0] = nums[0];
    if(dp[i]!=-1) return dp[i];
    
    int notPick = f(i-1, nums, dp);
    
    int pick = nums[i];
    if(i>1) pick += f(i-2, nums, dp);
    
    return dp[i] = max(pick, notPick);
}
//tabulation
int maximumNonAdjacentSum1(vector<int> &nums){
    int n= nums.size();
    vector<int> dp(n, -1);
    
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    for(int i=2; i<n; i++) {
        int notPick = dp[i-1];
        int pick = nums[i] + dp[i-2];

        dp[i] = max(pick, notPick);
    }
    
    return dp[n-1];
    //return f(n-1, nums, dp);
}
//space optimized
int maximumNonAdjacentSum(vector<int> &nums){
    int n= nums.size();
    
    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);
    int curr;
    
    for(int i=2; i<n; i++) {
        curr = max(prev1, nums[i] + prev2);
        
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}
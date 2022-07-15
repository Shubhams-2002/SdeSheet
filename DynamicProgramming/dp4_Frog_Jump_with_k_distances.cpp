#include<bits/stdc++.h>
using namespace std;

//memoization
int f(int i, int k, vector<int> &heights, vector<int>& dp) {
    if(i==0) return dp[0] = 0;
    if(dp[i]!=-1) return dp[i];
    
    int mini = INT_MAX;
    for(int j=1; j<=k; j++) {
        if(i>=j) {
            mini = min( mini, f(i-j, k, heights, dp) + abs(heights[i] - heights[i-j]) );
        }
    }
    
    return dp[i] = mini;
}
//tabulation
int frogJump(int n, int k, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    for(int i=1; i<n; i++) {
        int mini = INT_MAX;
        for(int j=1; j<=k; j++) {
            if(i>=j) {
                mini = min( mini, dp[i-j] + abs(heights[i] - heights[i-j]) );
            }
        }

        dp[i] =mini;
    }
    return dp[n-1];
    //return f(n-1, k, heights, dp);
}
//space optimized
//you can optimize space by using array of k size as you need only last k values

int main() {

  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  int k=2;
  vector<int> dp(n,-1);
  cout<<frogJump(n, k, height);
}
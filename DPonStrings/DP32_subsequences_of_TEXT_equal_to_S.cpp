#include<bits/stdc++.h>
int subsequenceCountingHelper( int i, int j, string& t, string& s, vector<vector<int>>& dp) {
    if(j<0) return 1;
    else if(i<0 && j>=0) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int not_take = subsequenceCountingHelper( i-1, j, t, s, dp);
    
    int take = 0;
    if(t[i] == s[j]) take = subsequenceCountingHelper( i-1, j-1, t, s, dp);
    
    int mod = 1e9 + 7; 
    return dp[i][j] = (not_take + take) % mod;
}
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<vector<int>> dp (lt, vector<int> (ls, -1)) ;
    return subsequenceCountingHelper(lt-1, ls-1, t, s, dp);
} 
// tabulation
int subsequenceCounting(string &t, string &s, int lt, int ls)
{
	int mod = 1e9+7;

	// Declaring our 2D DP table.
	vector<vector<int>> dp(lt+1, vector<int>(ls+1));

	// Setting DP[i][0] to 1 as s is matched with some subsequence of t. 
	for(int i = 0; i <= lt; i++){
		dp[i][0] = 1;
	}

	// Taversing and filling values for DP.
	for(int i = 1; i <= lt; i++){
		for(int j = 1; j <= ls; j++)
		{
			if(t[i-1] == s[j-1]){
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	// Our answer will be stored in dp[lt][ls].
	return dp[lt][ls];
}
//2n space
int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    int mod = 1e9+7;

    vector<int> prev(ls+1, 0), curr(ls+1, 0);
    prev[0]=curr[0]=1;

    // Taversing and filling values for DP.
    for(int i = 1; i <= lt; i++){
        for(int j = 1; j <= ls; j++)
        {
            if(t[i-1] == s[j-1]){
                curr[j] = (prev[j-1] + prev[j]) % mod;
            }
            else{
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }

    // Our answer will be stored in dp[lt][ls].
    return prev[ls];
}
// n space
int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    int mod = 1e9+7;

    // Declaring our 2D DP table.
    vector<int> prev(ls+1, 0);
    prev[0]=1;

    // Taversing and filling values for DP.
    for(int i = 1; i <= lt; i++){
        for(int j = ls; j >= 1; j--)
        {
            if(t[i-1] == s[j-1]){
                prev[j] = (prev[j-1] + prev[j]) % mod;
            }
        }
    }

    // Our answer will be stored in dp[lt][ls].
    return prev[ls];
}
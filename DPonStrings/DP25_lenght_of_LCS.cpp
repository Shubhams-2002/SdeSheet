#include<bits/stdc++.h>

//memoization
int f(int i, int j, string &s, string &t, vector< vector<int> > &dp) {
    if(i<0 || j<0) return 0;
    if( dp[i][j] != -1 ) return dp[i][j];
    
    if(s[i] == t[j]){
        return dp[i][j] = 1 + f(i-1, j-1, s, t, dp);
    }
    else {
        return dp[i][j] = max( f(i-1, j, s, t, dp) , f(i, j-1, s, t, dp) );
    }
}
int lcs1(string s, string t)
{
    int n = s.length(), m = t.length();
    vector< vector<int> > dp(n, vector<int>(m, -1) );
    return f(n-1, m-1, s, t, dp);
}

//tabulation
int lcs2(string s, string t)
{
    int n = s.length(), m = t.length();
    vector< vector<int> > dp(n+1, vector<int>(m+1, 0) );

    //first row and first col is base case, initialized to 0
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max( dp[i-1][j] , dp[i][j-1] );
            }
        }
    }
    
    return dp[n][m];
}

//space optimized
int lcs(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<int> prev(m+1, 0);
    vector<int> curr(m+1, 0);

    //first row and first col is base case, initialized to 0
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i-1] == t[j-1]){
                curr[j] = 1 + prev[j-1];
            }
            else {
                curr[j] = max( prev[j] , curr[j-1] );
            }
        }
        prev = curr;
    }
    
    return prev[m];
}
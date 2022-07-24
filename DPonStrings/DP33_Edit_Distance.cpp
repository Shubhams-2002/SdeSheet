#include<bits/stdc++.h>

//memoization
int f(int i, int j, string &str1, string &str2, vector< vector<int> > &dp) {
    if(j<0) return i+1; //remaining chars need to be deleted
    if(i<0 && j>=0) return j+1; //insert
    if(dp[i][j] != -1) return dp[i][j];
    
    if(str1[i]==str2[j]) {
        return dp[i][j] = f(i-1, j-1, str1, str2, dp);
    }
    else {
        //if you insert after i, then i+1 and j matches
        int insert = 1 + f(i, j-1, str1, str2, dp);
        //if you delete at i, then we try to match from i-1
        int delet  = 1 + f(i-1, j, str1, str2, dp);
        //if you replace at i, then i and j matches
        int replace= 1 + f(i-1, j-1, str1, str2, dp);
        return dp[i][j] = min({ insert, delet, replace });
    }
}
int editDistance1(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    vector< vector<int> > dp(n, vector<int>(m, -1) );
    return f(n-1, m-1, str1, str2, dp);
}

//tabulation
int editDistance2(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    vector< vector<int> > dp(n+1, vector<int>(m+1, 0) );
    
    for(int j=0; j<=m; j++) dp[0][j] = j;
    for(int i=0; i<=n; i++) dp[i][0] = i;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            
            if(str1[i-1]==str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                int insert = 1 + dp[i][j-1];
                int delet  = 1 + dp[i-1][j];
                int replace= 1 + dp[i-1][j-1];
                dp[i][j] = min({ insert, delet, replace });
            }
            
        }
    }
    
    return dp[n][m];
}

//space optimized
int editDistance(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    vector<int> prev(m+1, 0);
    vector<int> curr(m+1, 0);
    
    for(int j=0; j<=m; j++) prev[j] = j;
    
    for(int i=1; i<=n; i++) {
        curr[0] = i;
        for(int j=1; j<=m; j++) {
            
            if(str1[i-1]==str2[j-1]) {
                curr[j] = prev[j-1];
            }
            else {
                int insert = 1 + curr[j-1];
                int delet  = 1 + prev[j];
                int replace= 1 + prev[j-1];
                curr[j] = min({ insert, delet, replace });
            }
            
        }
        prev = curr;
    }
    
    return prev[m];
}
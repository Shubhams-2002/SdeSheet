#include<bits/stdc++.h>
//you can't use memoization to print LCS, because dp table does not get completely filled
//tabulation
int lcs1(string s, string t)
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
    
    int i=n, j=m;
    string ans = "";
    while(i>0 && j>0) {
        if(s[i-1] == t[j-1]) {
            ans += s[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
    reverse( ans.begin(), ans.end() );
    cout<<ans<<endl;
    
    return dp[n][m];
}
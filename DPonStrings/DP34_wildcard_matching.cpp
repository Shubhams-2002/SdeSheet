#include<bits/stdc++.h>
//only take note of isAllStar and pattern[i]=='*'
bool isAllStar(int i, string &pattern) {
    for(int k=0; k<=i; k++) {
        if(pattern[k]!='*') return false;
    }
    return true;
}
bool f(int i, int j, string &pattern, string &text, vector< vector<int> > &dp)
{
    if(i<0 && j<0) return true;
    else if(i<0 && j>=0) return false;
    else if(i>=0 && j<0) return isAllStar(i, pattern);
    if( dp[i][j] != -1 ) return  dp[i][j];
    
    if( pattern[i]==text[j] || pattern[i]=='?' ) {
        return dp[i][j] = f(i-1, j-1, pattern, text, dp);
    }
    else if( pattern[i]=='*' ) {
        //i-1,j is that you choose to match * with empty string
        //i,j-1 is that you choose to match * with jth char in text
        //and by recurrsion, you will eventually take more chars
        return dp[i][j] = f(i - 1, j, pattern, text, dp) || f(i, j - 1, pattern, text, dp);
    }
    else {
        return dp[i][j] = false;
    }
}
bool wildcardMatching(string pattern, string text)
{
    int n = pattern.length();
    int m = text.length();
    vector< vector<int> > dp(n, vector<int>(m, -1) );
    return f(n-1, m-1, pattern, text, dp);
}
//similarly do tabulation
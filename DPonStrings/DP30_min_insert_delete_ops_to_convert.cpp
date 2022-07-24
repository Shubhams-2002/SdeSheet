#include<bits/stdc++.h>
int lcs(string &s, string &t)
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
int canYouMake(string &str, string &ptr)
{
    int LCS = lcs(str, ptr);
    //don't delete common chars
    int deletions = str.length() - LCS;
    //don't insert common chars
    int insertions = ptr.length() - LCS;
    return deletions + insertions;
}
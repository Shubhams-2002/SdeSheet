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
int longestPalindromeSubseq(string s) {
        //Longest Palindromic Subsequence is the LCS of string and its reverse
        string t = "";
        for(int i=s.length()-1; i>=0; i--) t += s[i];
        return lcs(s, t);
}
int minInsertion(string &str)
{
    //insertions can be made anywhere in the string
    //find the length of Longest Palindromic Subsequence 
    //the chars in this subsequence are already a pallindrome and
    //hence we only need the duplicates of remaining chars to be insereted
    return str.length() - longestPalindromeSubseq(str);
}
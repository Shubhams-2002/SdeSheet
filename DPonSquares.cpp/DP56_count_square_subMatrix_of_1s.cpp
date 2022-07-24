#include<bits/stdc++.h>
int countSquares(int n, int m, vector<vector<int>> &arr) {
    //dp[i][j] stores no. of squares whose bottom right is cell[i][j]
    vector<vector<int>> dp(n, vector<int> (m,0) );
    
    //first row and first column is the base case and are
    //already initialized to 0/1 as they can't expand any further
    for(int i=0; i<n; i++) dp[i][0] = arr[i][0];
    for(int j=1; j<m; j++) dp[0][j] = arr[0][j];

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(arr[i][j]) {
                //1 stands of itself and min stands for how far it can expand
                dp[i][j] = 1 + min( dp[i-1][j], 
                                   min(dp[i-1][j-1], dp[i][j-1]) );
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
        
    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cnt = cnt + dp[i][j];
        }
    }            
    
    return cnt;
}
#include<bits/stdc++.h>

//f(i,j) represents minimum cost to complete cuts from i to j including i and j
//cuts are 1,3,4 & c=3
//modify it to '0',1,3,4,'5'
//now call f(1,c) i.e. from 1 to 4
//cost to make the cut will be cuts[i-1]-cuts[j+1] i.e. '5'-'0'

//memoization
int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int mini = 1e9;
    for(int k=i; k<=j; k++) {
        int a = cuts[j+1]-cuts[i-1] + f(i, k-1, cuts, dp) + f(k+1,j, cuts, dp);
        mini = min( mini, a );
    }
    
    return dp[i][j] = mini;
}
int cost1(int n, int c, vector<int> &cuts){
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    sort( cuts.begin(), cuts.end() );
    
    vector<vector<int>> dp( c+1, vector<int>(c+1,-1) );
    return f(1, c, cuts, dp);
}

//tabulation
int cost(int n, int c, vector<int> &cuts){
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    sort( cuts.begin(), cuts.end() );
    
    vector<vector<int>> dp( c+2, vector<int>(c+2,0) );
    for(int i=c; i>0; i--) {
        for(int j=i; j<=c; j++) {
            int mini = 1e9;
            for(int k=i; k<=j; k++) {
                int a = cuts[j+1]-cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                mini = min( mini, a );
            }

            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}
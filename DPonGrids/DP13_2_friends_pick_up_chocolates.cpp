#include<bits/stdc++.h>

//memoization
int f(int i, int j1, int j2,int r, int c, vector<vector<int>> &grid, 
      vector<vector<vector<int>>> &dp) {
    if(j1<0 || j1>=c || j2<0 || j2>=c) return -1e9; 
    if(i==r) return 0;
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    
    int maxi = INT_MIN;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {

          int chocolates = (j1==j2)? grid[i][j1] : grid[i][j1]+grid[i][j2];
          int ans = chocolates + f(i+1, j1+di, j2+dj, r, c, grid, dp);
            
          maxi = max(maxi, ans);
        }
    }
    
    return dp[i][j1][j2] = maxi;
}
int maximumChocolates1(int r, int c, vector<vector<int>> &grid) {
    vector < vector < vector < int >>> dp(r, vector < vector < int >> (c, vector < int > (c, -1)));
    
    return f(0,0,c-1, r, c, grid, dp);
}

//tabulation
int maximumChocolates2(int r, int c, vector<vector<int>> &grid) {
    vector < vector < vector < int >>> dp(r, vector < vector < int >> (c, vector < int > (c, -1)));
    
    for(int j1=0; j1<c; j1++) {
        for(int j2=0; j2<c; j2++) {
            //dp[r][j1][j2] = 0;
            dp[r-1][j1][j2] = (j1==j2)? grid[r-1][j1] : grid[r-1][j1]+grid[r-1][j2];
        }
    }
    
    for(int i=r-2; i>=0; i--) {
        for(int j1=0; j1<c; j1++) {
            for(int j2=0; j2<c; j2++) {
                
                int maxi = INT_MIN;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {

                        int ans = (j1==j2)? grid[i][j1] : grid[i][j1]+grid[i][j2];
                        if(j1+di>=0 && j1+di<c && j2+dj>=0 && j2+dj<c)
                            ans += dp[i+1][j1+di][j2+dj];
                        else 
                            ans = -1e8;

                        maxi = max(maxi, ans);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    
    return dp[0][0][c-1];
}

//space optimized
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<int> > next(c, vector<int>(c,0) );
    vector<vector<int> > curr(c, vector<int>(c,0) );
    
    for(int i=r-2; i>=0; i--) {
        for(int j1=0; j1<c; j1++) {
            for(int j2=0; j2<c; j2++) {
                
                int maxi = INT_MIN;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {

                        int ans = (j1==j2)? grid[i][j1] : grid[i][j1]+grid[i][j2];
                        if(j1+di>=0 && j1+di<c && j2+dj>=0 && j2+dj<c)
                            ans += next[j1+di][j2+dj];
                        else 
                            ans = -1e8;

                        maxi = max(maxi, ans);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        swap(next, curr);
    }
    
    return next[0][c-1];
}
#include<bits/stdc++.h>
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> z(n+1, 1e9);
    vector<vector<int>> d0(n+1, z);
    vector<vector<int>> d1(n+1, z);
    
    for(int i=1; i<=n; i++) {
        d0[i][i]=0;
    }
    for(int i=0; i<m; i++) {
        d0[edges[i][0]][edges[i][1]] = edges[i][2];
    }
    d1 = d0;
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(d0[i][k]==1e9 || d0[k][j]==1e9) continue;
                d1[i][j] = min( d0[i][j], d0[i][k]+d0[k][j] );
            }
        }
        d0 = d1;
    }
    
    return d1[src][dest];
}
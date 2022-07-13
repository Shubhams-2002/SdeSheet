#include<bits/stdc++.h>
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;
    
    //relax all edges n-1 times
    //any path can have at max n-1 edges
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt= edges[j][2];
            
            if(dist[u]!=1e9 && dist[v] > dist[u]+wt) {
                dist[v] = dist[u]+wt;
            }
            //some test cases got failed without 1st condn
            //because dist[u] will be a finite no. and wt can be a negative no.
            //and if at the same time dist[v]=1e9 
            //then dist[v] will be less than dist[u]+wt
        }
    }
    
    //check for negative cycle 
    bool negCycle = false;
    for(int j=0; j<m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt= edges[j][2];
            
            if(dist[v] > dist[u]+wt) {
                //if dist of any vertex is getting relaxed, then negCycle is present
                negCycle = true;
                break;
            }
    }
    
    return dist[dest];
}
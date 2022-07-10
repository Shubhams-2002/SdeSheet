#include<bits/stdc++.h>
bool dfs(int node, int prev, vector<bool>& vis, vector<int> adj[]) 
{
    vis[node] = true;
    
    for(auto it : adj[node]) {
        if( !vis[it] ) {
            if( dfs(it, node, vis, adj) ) return true;
        }
        else if(it != prev) {
            return true;
        }
    }
    
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    for(int i=0; i<edges.size(); i++) {
        adj[ edges[i][0] ].push_back( edges[i][1] );
        adj[ edges[i][1] ].push_back( edges[i][0] );
    }
    
    vector<bool> vis(n+1, false);
    for(int i=1; i<=n; i++) {
        if( !vis[i] ) {
            if( dfs(i, -1, vis, adj) ) {
                return "Yes";
            }
        }
    }
    
    return "No";
}

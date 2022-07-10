#include<bits/stdc++.h>
void dfs(int node, vector<bool>& vis, vector<int> adj[], vector<int>& ds) {
    ds.push_back(node);
    vis[node] = true;
    
    for(auto it : adj[node]) {
        if( !vis[it] ) {
            dfs(it, vis, adj, ds);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    
    vector<int> adj[V];
    for(int i=0; i<edges.size(); i++) {
        adj[ edges[i][0] ].push_back( edges[i][1] );
        adj[ edges[i][1] ].push_back( edges[i][0] );
    }
    
    vector<bool> vis(V, false);
    int cnt=0;
    for(int i=0; i<V; i++) {
        if( !vis[i] ) {
            vector<int> connected_comp;
            dfs(i, vis, adj, connected_comp);
            ans.push_back(connected_comp);
        }
    }
    
    return ans;
}
#include<bits/stdc++.h>
bool dfs(int node, vector<bool>& currDFSvis, vector<bool>& vis, vector<int> adj[]) 
{
    vis[node] = true;
    currDFSvis[node] = true;
    for(auto it : adj[node]) {
        if( !vis[it] ) {
            if( dfs(it, currDFSvis, vis, adj) ) return true;
        }
        else if(currDFSvis[it]) {
            return true;
        }
    }
    currDFSvis[node] = false;
    
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> adj[n+1];
    for(int i=0; i<edges.size(); i++) {
        adj[ edges[i].first ].push_back( edges[i].second );
    }
    
    vector<bool> vis(n+1, false);
    vector<bool> currDFSvis(n+1, false);
    for(int i=1; i<=n; i++) {
        if( !vis[i] ) {
            if( dfs(i, currDFSvis, vis, adj) ) {
                return 1;
            }
        }
    }
    
    return 0;
}
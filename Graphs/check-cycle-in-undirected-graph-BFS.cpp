#include<bits/stdc++.h>
bool bfs(int node, vector<bool>& vis, vector<int> adj[]) 
{
    queue< pair<int, int> > q;
    q.push( {node, -1} );
    vis[node] = true;
    
    while( !q.empty() ) {
        int vertex = q.front().first;
        int prev = q.front().second;
        q.pop();
        
        for(auto it : adj[vertex]) {
            if( !vis[it] ) {
                q.push( {it, vertex} );
                vis[it] = true;
            }
            else if(it != prev) {
                return true;
            }
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
            if( bfs(i, vis, adj) ) {
                return "Yes";
            }
        }
    }
    
    return "No";
}

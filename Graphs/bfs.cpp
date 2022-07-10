#include<bits/stdc++.h>
void bfs(int node, vector<bool>& vis, vector<int> adj[], vector<int>& ds) 
{
    queue<int> q;
    q.push(node);
    vis[node] = true;
    
    while( !q.empty() ) {
        int v = q.front();
        q.pop();
        ds.push_back(v);
        
        for( auto it : adj[v] ) {
            if( !vis[it] ) {
                q.push(it);
                vis[it] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> ans;
    
    vector<int> adj[vertex];
    for(int i=0; i<edges.size(); i++) {
        adj[ edges[i].first ].push_back( edges[i].second );
        adj[ edges[i].second ].push_back( edges[i].first );
    }
    
    for(int i=0; i<vertex; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    vector<bool> vis(vertex, false);
    for(int i=0; i<vertex; i++) {
        if( !vis[i] ) {
            bfs(i, vis, adj, ans);
        }
    }
    
    return ans;
}
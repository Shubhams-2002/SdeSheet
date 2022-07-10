#include<bits/stdc++.h>
bool bfs(int node, vector<int>& color, vector<int> adj[]) 
{
    queue<int> q;
    q.push(node);
    color[node] = 0;
    
    while( !q.empty() ) {
        int v = q.front();
        q.pop();
        
        for( auto it : adj[v] ) {
            if( color[it]==-1 ) {
                q.push(it);
                color[it] = 1-color[v];
            }
            else if(color[it] == color[v]) {
                return false;
            }
        }
    }
    
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    int vertex = edges.size();
    
    vector<int> adj[vertex];
    for(int i=0; i<edges.size(); i++) {
        for(int j=0; j<edges[0].size(); j++) {
            if(edges[i][j]==1) {
                adj[ i ].push_back( j );
                adj[ j ].push_back( i );
            }
        }
    }
    
    vector<int> color(vertex, -1);
    for(int i=0; i<vertex; i++) {
        if( color[i]==-1 ) {
            if(bfs(i, color, adj)==false) return false;
        }
    }
    
    return true;
}
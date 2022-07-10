#include<bits/stdc++.h>
bool dfs(int node, int prev, vector<int>& color, vector<int> adj[]) 
{
    if(prev==-1) color[node] = 0;
    else color[node] = 1-color[prev];
    
    for(auto it : adj[node]) {
        if( color[it]==-1 ) {
            if( dfs(it, node, color, adj) == false) return false;
        }
        else if( color[it]== color[node]) {
            return false;
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
            if(dfs(i, -1, color, adj)==false) return false;
        }
    }
    
    return true;
}
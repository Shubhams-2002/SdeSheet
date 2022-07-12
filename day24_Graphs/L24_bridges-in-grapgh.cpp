#include<bits/stdc++.h>
void dfs(int node, int parent, int& timer, vector<int>& disc, vector<int>& low, vector<bool> &vis, vector<vector<int>>& ans, vector<int> adj[]) 
{
    vis[node] = true;
    disc[node] = low[node] = timer;
    timer++;
    
    for(auto it : adj[node]) {
        if( !vis[it] ) {
            dfs(it, node, timer, disc, low, vis, ans, adj);
            
            //update low of node, 
            //just in case low of neighbour has got updated 
            //as it may have found back edge
            low[node] = min( low[node], low[it] );
            
            //check if it is a bridge
            //low that is quickest way to get to a node
            //if that of nbr is greater than disc[node]
            //that means their is only one way to get nbr 
            //and that is only through this node by this edge
            if( low[it] > disc[node] ) {
                vector<int> bridge;
                bridge.push_back(node);
                bridge.push_back(it);
                ans.push_back(bridge);
            }
        }
        else if(it != parent) {
            //cycle detected or aka back edge
            //hence this edge can't be a bridge
            low[node] = min( low[node], disc[it] );
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    vector<vector<int>> ans;
    vector<int> adj[v];
    for(int i=0; i<edges.size(); i++) {
        adj[ edges[i][0] ].push_back( edges[i][1] );
        adj[ edges[i][1] ].push_back( edges[i][0] );
    }
    
    int timer=0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    vector<bool> vis(v, false);
    for(int i=0; i<v; i++) {
        if( !vis[i] ) {
            dfs(i, -1, timer, disc, low, vis, ans, adj);
        }
    }
    
    return ans;
}
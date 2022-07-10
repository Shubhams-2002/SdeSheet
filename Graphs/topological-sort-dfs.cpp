#include<bits/stdc++.h>
void dfs(int node, vector<bool>& vis, vector<int> adj[], stack<int>& st) 
{
    vis[node] = true;
    
    for(auto it : adj[node]) {
        if( !vis[it] ) {
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    stack<int> st;
    
    vector<int> adj[v];
    for(int i=0; i<edges.size(); i++) {
        adj[ edges[i][0] ].push_back( edges[i][1] );
    }
    
    vector<bool> vis(v, false);
    for(int i=0; i<v; i++) {
        if( !vis[i] ) {
            dfs(i, vis, adj, st);
        }
    }
    
    while( !st.empty() ) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
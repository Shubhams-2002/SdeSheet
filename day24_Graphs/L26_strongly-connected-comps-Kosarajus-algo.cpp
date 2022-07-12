#include<bits/stdc++.h>
void topoDFS(int node, vector<bool>& vis, vector<int> adj[], stack<int>& st)
{
    vis[node] = true;
    
    for(int it : adj[node]) {
        if( !vis[it] ){
            topoDFS(it, vis, adj, st);
        }
    }
    
    st.push(node);
}

void dfs(int node, vector<bool>& vis, vector<int> adj[], vector<int>& scc) {
    vis[node] = true;
    scc.push_back(node);
    for(int it : adj[node]) {
        if( !vis[it] ){
            dfs(it, vis, adj, scc);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n];
    vector<int> adjT[n];
    for(int i=0; i<edges.size(); i++) {
        adj[ edges[i][0] ].push_back( edges[i][1] );
        adjT[ edges[i][1] ].push_back( edges[i][0] );
    }
    
    //step 1 : loose topological sort
    vector<bool> vis(n, false);
    stack<int> st;
    for(int i=0; i<n; i++) {
        if( !vis[i] ) {
            topoDFS(i, vis, adj, st);
        }
    }
    
    //step 2 : reverse directions of edges, done at line 20
    //if diectly adj list was provided then
//     for(int i = 0; i<n; i++) {
//         vis[i] = 0; 
//         for(auto it: adj[i]) {
//             adjT[it].push_back(i); 
//         }
//     }
    
    //step 3 : dfs with revsersed edges
    vector<vector<int>> ans;
    vector<bool> vis1(n, false);
    while( !st.empty() ) {
        int node = st.top();
        st.pop();
        
        if( !vis1[node] ) {
            vector<int> scc;
            dfs(node, vis1, adjT, scc);
            ans.push_back(scc);
        }
    }
    
    return ans;
}
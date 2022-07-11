#include<bits/stdc++.h>
#define INF INT_MAX
void topo_dfs(int node, vector<bool>& vis, vector<pair< int, int> > adj[v], stack<int>& st) 
{
    vis[node] = true;
    
    for(auto it : adj[node]) {
        if( !vis[it.first] ) {
            topo_dfs(it.first, vis, adj, st);
        }
    }
    st.push(node);
}

vector<int> singleSourceShortestPathDAG(vector<pair< int, int> > adj[], int n, int src)  {
    stack<int> st;
    
    vector<bool> vis(n, false);
    for(int i=0; i<n; i++) {
        if( !vis[i] ) {
            topo_dfs(i, vis, adj, st);
        }
    }

    vector<int> dist(n, INF);
    dist[src] = 0;
    
    while( !st.empty() ) {
        int u = st.top();
        st.pop();

        if(dist[u] != INF) {
            //earlier nodes can't be reached from source because of directed edges
            for(auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if( dist[v] > dist[u]+wt ) {
                    dist[v] = dist[u]+wt;
                }
            } 
        }
    }

    return dist;
}
#include<bits/stdc++.h>
#define INF INT_MAX
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector< pair<int,int> > adj[n+1];
    for(int i=0; i<m; i++) {
        adj[ g[i].first.first ].push_back( {g[i].first.second, g[i].second} );
        adj[ g[i].first.second ].push_back( {g[i].first.first, g[i].second} );
    }
    
    vector<int> key(n+1, INF);
    vector<int> parent(n+1, -1);
    vector<bool> mst(n+1, false);
    
    key[1] = 0;
    parent[1] = -1;
    
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push( {key[1],1} );
    
    while( !pq.empty() ) {
        int u = pq.top().second;
        pq.pop();
        mst[u] = true;
        
        for(auto it : adj[u]) {
            int v = it.first;
            int wt = it.second;
            
            if(!mst[v] && key[v] > wt) {
                key[v] = wt;
                parent[v] = u;
                pq.push( {key[v],v} );
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n; i++) {
        ans.push_back( { {i,parent[i]}, key[i] });
    }
    return ans;
}
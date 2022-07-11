#include<bits/stdc++.h>
#define INF 2147483647
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector< pair<int, int> > adj[vertices];
    for(int i=0; i<vec.size(); i++) {
        adj[ vec[i][0] ].push_back( {vec[i][1], vec[i][2]} );
        adj[ vec[i][1] ].push_back( {vec[i][0], vec[i][2]} );
    }
    
    vector<int> dist(vertices, INF);
    dist[source] = 0;
    
    //minimum priority_queue
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int>> > pq; 
    pq.push( {dist[source], source} );
    
    while( !pq.empty() ) {
        int u = pq.top().second;
        pq.pop();
        
        for(auto it : adj[u] ) {
            int v = it.first;
            int wt = it.second;
            
            if(dist[v] > dist[u]+wt) {
                dist[v] = dist[u]+wt;
                pq.push( {dist[v], v} );
            }
        }
    }
    
    return dist;
}

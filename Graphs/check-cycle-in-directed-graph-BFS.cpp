#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> adj[n+1];
    vector<int> indeg(n+1, 0);
    for(int i=0; i<edges.size(); i++) {
        adj[ edges[i].first ].push_back( edges[i].second );
        indeg[ edges[i].second ]++;
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(indeg[i]==0) {
            q.push(i);
        }
    }
    
    int cnt=0;
    while( !q.empty() && cnt<=n) {
        cnt++;
        int vertex = q.front();
        q.pop();
        
        for(auto it : adj[vertex]) {
            indeg[it]--;
            if(indeg[it]==0) {
                q.push(it);
            }
        }
    }
    
    return (cnt==n)? 0 : 1;
}
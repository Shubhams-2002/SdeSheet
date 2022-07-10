#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    
    vector<int> adj[v];
    vector<int> indeg(v, 0);
    for(int i=0; i<edges.size(); i++) {
        adj[ edges[i][0] ].push_back( edges[i][1] );
        indeg[ edges[i][1] ]++;
    }
    
    queue<int> q;
    for(int i=0; i<v; i++) {
        if(indeg[i]==0) {
            q.push(i);
        }
    }
    //no need to worry about diconnected components
    //each of them will have atleast one vertex with indeg==0
    //that wiil be used in BFS traversal
    
    while( !q.empty() ) {
        int vertex = q.front();
        q.pop();
        ans.push_back(vertex);
        
        for(auto it : adj[vertex]) {
            indeg[it]--;
            if(indeg[it]==0) {
                q.push(it);
            }
        }
    }
    return ans;
}
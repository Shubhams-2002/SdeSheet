#include<bits/stdc++.h>
int find(int node, vector<int>& parent) {
    if(parent[node] == node) {
        return node;
    }
    
    //return but only after compressing the path using recursion
    return parent[node] = find(parent[node], parent);
}

void union_set(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = find(u, parent);
    v = find(v, parent);
    if(rank[u] < rank[v]) {
        parent[u] = v;
    } 
    else if(rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        rank[u]++;
        parent[v] = u;
    }
}

struct edge {
    int u;
    int v;
    int wt;
    edge(int v1, int v2, int weight){
        u = v1;
        v = v2;
        wt = weight;
    }
};

bool comp(edge e1, edge e2) {
    return (e1.wt < e2.wt);
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    vector<int> parent(n+1);
    for(int i=0; i<=n; i++) parent[i]=i;
    vector<int> rank(n+1, 0);
    
    vector<edge> edges;
    for(int i=0; i<m; i++) {
        edges.push_back( edge( graph[i][0], graph[i][1], graph[i][2]) );
    }
    sort( edges.begin(), edges.end(), comp);
    
    int cost=0;
    vector<pair<pair<int, int>, int>> ans;
    for(int i=0; i<m; i++) {
        if( find(edges[i].u, parent) != find(edges[i].v, parent) ){
            ans.push_back( { {edges[i].u, edges[i].v}, edges[i].wt } );
            cost += edges[i].wt;
            union_set(edges[i].u, edges[i].v, parent, rank);
        }
    }
    
    return cost;
}
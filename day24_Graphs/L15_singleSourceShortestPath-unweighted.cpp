#include<bits/stdc++.h>
#define INF INT_MAX
vector < int > bfsOfGraph(int V, vector < int > adj[], int src) {
      vector < int > dist(V, INF);
      queue < int > q;

      q.push(src);
      dist[src] = 0;
      
      while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it: adj[node]) {
          if (dist[it] > dist[node]+1) {
            dist[it] = dist[node]+1;
            q.push(it);
          }
        }
      }

      return dist;
}
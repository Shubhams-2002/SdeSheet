#include<bits/stdc++.h>

class Solution {
  public:
    void dfs(int node, int parent, int& timer, vector<int>& disc, vector<int>& low, vector<bool>& vis, vector<int>adj[], vector<bool>& ap) {
        vis[node] = true;
        disc[node] = low[node] = timer;
        timer++;
        int children=0;
        
        for(int it : adj[node]) {
            if( !vis[it] ) {
                //count only non visted nbrs as children as visited will be parent
                children++;
                
                dfs(it, node, timer, disc, low, vis, adj, ap);
                
                low[node] = min( low[node], low[it] );
                
                if(parent!=-1 && low[it]>=disc[node]) {
                    ap[node] = true;
                }
            }
            else if( it != parent ) {
                low[node] = min( low[node], disc[it] );
            }
        }
        
        if(parent==-1 && children>1) {
            ap[node] = true;
        }
    }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> ans;
        
        int timer = 0;
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<bool> vis(V, false);
        vector<bool> ap(V, false);
        
        for(int i=0; i<V; i++) {
            if( !vis[i] ) {
                dfs(i, -1, timer, disc, low, vis, adj, ap);
            }
        }
        
        for(int i=0; i<V; i++) {
            if(ap[i]) ans.push_back(i);
        }
        if(ans.size()==0) ans.push_back(-1);
        return ans;
    }
};
#include<bits/stdc++.h>
class Solution {
public:
    void bfs(Node* node, unordered_map<Node*, Node*>& map) 
    {
        if(!node) return;
        
        queue<Node*> q;
        q.push(node);
        
        unordered_set<Node*> vis;
        vis.insert(node);

        while( !q.empty() ) {
            Node* v = q.front();
            q.pop();
            
            Node* new_v = new Node(v->val);
            map[v] = new_v;

            for( Node* adj : v->neighbors ) {
                if( !vis.count(adj) ) {
                    q.push(adj);
                    vis.insert(adj);
                }
            }
        }
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> map;
        bfs(node, map);
        
        for(pair<Node*, Node*> p : map) {
            Node* oldv = p.first;
            Node* newv = p.second;
            
            for(Node* it : oldv->neighbors) {
                newv->neighbors.push_back( map[it] );
            }
        }
        
        return map[node];
    }
};
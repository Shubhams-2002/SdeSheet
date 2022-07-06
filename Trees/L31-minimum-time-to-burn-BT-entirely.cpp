#include<bits/stdc++.h>
class Solution {
    void getParents(Node* root, unordered_map<Node*, Node*>& parent){
        queue<Node*> q;
        q.push(root);
        
        while( !q.empty() ) {
            Node* node = q.front();
            q.pop();
            
            if(node->left) {
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right) {
                q.push(node->right);
                parent[node->right] = node;
            }
        }
    }
    
    Node* getTarget(Node* root, int target) {
        if(root==NULL || root->data==target) {
            return root;
        }
        
        if( getTarget(root->left, target) != NULL) {
            return getTarget(root->left, target);
        }
        else {
            return getTarget(root->right, target);
        }
    }
  public:
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*, Node*> parent;
        getParents(root, parent);
        
        Node* tar = getTarget(root, target);
        
        unordered_set<Node*> visited;
        visited.insert(tar);
        
        queue<Node*> q;
        q.push(tar);
        
        int ans=0;
        while( !q.empty() ) {
            int breadth = q.size();
            while(breadth) {
                breadth--;
                Node* node = q.front();
                q.pop();

                if(parent.count(node) && !visited.count(parent[node]) ) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }

                if(node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }

                if(node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
            }
            
            if( !q.empty() ) ans++;
        }
        return ans;
    }
};
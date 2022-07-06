#include<bits/stdc++.h>
class Solution {
    void getParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        
        while( !q.empty() ) {
            TreeNode* node = q.front();
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
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> parent;
        getParents(root, parent);
        
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        
        queue<TreeNode*> q;
        q.push(target);
        
        int dist=0;
        while(dist<k) {
            dist++;
            int breadth = q.size();
            while(breadth) {
                breadth--;
                TreeNode* node = q.front();
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
        }
        
         while( !q.empty() ) {
             ans.push_back( q.front()->val );
             q.pop();
         }
        
        return ans;
    }
};
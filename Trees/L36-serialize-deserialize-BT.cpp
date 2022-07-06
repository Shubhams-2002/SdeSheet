/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root) return ans;
        
        queue< TreeNode* > q;
        q.push(root);
        while( !q.empty() ) {
            TreeNode* node = q.front();
            q.pop();
            if(node) {
                ans.append( to_string(node->val) + ',');
                q.push(node->left);
                q.push(node->right);
            }
            else {
                ans.append( "#,");
            }
        }
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return NULL;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode( stoi(str) );
        queue<TreeNode*> q;
        q.push(root);
        
        while( !q.empty() ) {
            TreeNode* node = q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str=="#") {
                node->left = NULL;
            }
            else {
                TreeNode* leftChild = new TreeNode( stoi(str) );
                node->left = leftChild;
                q.push(node->left);
            }
             
            getline(s, str, ',');
            if(str=="#") {
                node->right = NULL;
            }
            else {
                TreeNode* rightChild = new TreeNode( stoi(str) );
                node->right = rightChild;
                q.push(node->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
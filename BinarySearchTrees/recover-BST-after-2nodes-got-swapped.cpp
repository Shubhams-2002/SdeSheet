#include<bits/stdc++.h>
class Solution {
    TreeNode* prev=NULL;
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* last=NULL;
    
public:
    void inorder(TreeNode* root) {
        if(!root) return;
        
        inorder(root->left);
        
        if(prev && prev->val > root->val) {
            if(first==NULL) {
                first = prev;
                second = root;
            }
            else {
                last = root;
            }
        }
        prev = root;
        
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        if(first && last) swap(first->val, last->val);
        else if(first && second) swap(first->val, second->val);
    }
};
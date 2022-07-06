#include<bits/stdc++.h>
class Solution {
    int leftHeight(TreeNode* root) {
        TreeNode* node = root->left;
        int h=0;
        while(node) {
            h++;
            node = node->left;
        }
        return h;
    }
    
    int rightHeight(TreeNode* root) {
        TreeNode* node = root->right;
        int h=0;
        while(node) {
            h++;
            node = node->right;
        }
        return h;
    }
    
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        
        if(lh==rh) return pow(2,lh+1)-1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
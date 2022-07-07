#include <bits/stdc++.h> 
TreeNode<int>* insertionInBST(TreeNode<int>* root, int val)
{
    if(!root) return new TreeNode<int>(val);
    
    TreeNode<int>* curr = root;
    while(curr) {
        if(val < curr->val) {
            if(curr->left) {
                curr = curr->left;
            }
            else {
                curr->left = new TreeNode<int>(val);
                break;
            }
        }
        else {
            if(curr->right) {
                curr = curr->right;
            }
            else {
                curr->right = new TreeNode<int>(val);
                break;
            }
        }
    }
    
    return root;
}
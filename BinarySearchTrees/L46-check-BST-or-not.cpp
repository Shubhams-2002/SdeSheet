#include <bits/stdc++.h> 
bool helper(BinaryTreeNode<int> *root, int low, int high) {
    if(!root) return true;
    
    return (root->data >= low) && (root->data <= high) 
        && helper(root->left, low, root->data)
        && helper(root->right, root->data, high);
}

bool validateBST(BinaryTreeNode<int> *root) {
    return helper(root, INT_MIN, INT_MAX);
}
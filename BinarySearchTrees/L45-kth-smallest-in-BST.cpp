#include <bits/stdc++.h> 
int helper(TreeNode<int> *root, int k, int& count) {
    if(!root) {
        return -1;
    }
    
    int left = helper(root->left, k, count);
    if(left != -1) return left;
    
    count++;
    if(count==k) return root->data;
    
    return helper(root->right, k, count);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    int count = 0;
    return helper(root, k, count);
}
#include <bits/stdc++.h> 
int helper(TreeNode<int> *root, int k, int& count) {
    if(!root) {
        return -1;
    }
    
    int right = helper(root->right, k, count);
    if(right != -1) return right;
    
    count++;
    if(count==k) return root->data;
    
    return helper(root->left, k, count);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int count = 0;
    return helper(root, k, count);
}
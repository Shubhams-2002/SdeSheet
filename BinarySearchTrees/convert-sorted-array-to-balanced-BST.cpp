#include <bits/stdc++.h>
//if array of keys to be made into BST were not sorted, sort them first
TreeNode<int>* buildTree(vector<int> &arr, int low, int high) {
    if(low>high) return NULL;
    
    int mid = (low+high)/2;
    TreeNode<int>* root = new TreeNode<int>( arr[mid] );
    
    root->left = buildTree(arr, low, mid-1);
    root->right= buildTree(arr, mid+1, high);
    
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return buildTree(arr, 0, n-1);
}
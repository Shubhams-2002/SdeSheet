#include<bits/stdc++.h>
TreeNode<int> *solve(vector<int> &inorder, vector<int> &preorder, 
                     unordered_map<int, int>& map, 
                     int preStart, int preEnd, int inStart, int inEnd)
{
    if(preStart>preEnd || inStart>inEnd) {
        return NULL;
    }
    TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);
    
    int inorderId = map[preorder[preStart]];
    int leftCnt = inorderId-inStart;
    root->left = solve(inorder, preorder, map, 
                      preStart+1, preStart+leftCnt, 
                      inStart, inorderId-1);
    root->right= solve(inorder, preorder, map, 
                      preStart+leftCnt+1, preEnd,
                      inorderId+1, inEnd);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int n = inorder.size();
    unordered_map<int, int> map;
    for(int i=0; i<n; i++) {
        map[ inorder[i] ] = i;
    }
    
    TreeNode<int> *root = solve(inorder, preorder, map,
                                0, n-1, 0, n-1);
    return root;
}
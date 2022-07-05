#include<bits/stdc++.h>
TreeNode<int>* solve(vector<int>& postOrder, vector<int>& inOrder,
                     unordered_map<int, int>& mp, 
                     int postStart, int postEnd, int inStart, int inEnd)
{
    if(postStart>postEnd || inStart>inEnd) {
        return NULL;
    }
    
    TreeNode<int>* root = new TreeNode<int>( postOrder[postEnd] );
    int inorderId = mp[ postOrder[postEnd] ];
    int leftCnt = inorderId-inStart;
    
    root->left = solve(postOrder, inOrder, mp,
                       postStart, postStart+leftCnt-1,
                       inStart, inorderId-1);
    root->right= solve(postOrder, inOrder, mp,
                       postStart+leftCnt, postEnd-1,
                       inorderId+1, inEnd);
    
    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
    //if(postOrder.size() != inOrder.size()) return NULL;
    
    int n = inOrder.size();
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++) {
        mp[ inOrder[i] ] = i;
    }
    
    TreeNode<int> *root = solve(postOrder, inOrder, mp,
                                0, n-1, 0, n-1);
    return root;
}

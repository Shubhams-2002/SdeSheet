#include<bits/stdc++.h>
TreeNode<int>* bulidTree(vector<int>& preOrder, int& i, int upper) {
    if(i==preOrder.size() || preOrder[i]>upper) {
        return NULL;
    }
    
    TreeNode<int>* root = new TreeNode<int>(preOrder[i]);
    i++;
    root->left = bulidTree(preOrder, i, root->data);
    root->right= bulidTree(preOrder, i, upper);
    
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder) {
    int i=0;
    return bulidTree(preOrder, i, INT_MAX);
}
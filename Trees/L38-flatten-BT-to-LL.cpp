#include<bits/stdc++.h>

//recursive method
class Solution {
    TreeNode* prev = NULL;
  public:
    void flatten(TreeNode* root) 
    {
        if(root==NULL) {
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};
//recursive without external prev
TreeNode<int>* flatten(TreeNode<int>* root, TreeNode<int>* prev) 
    {
        if(root==NULL) {
            return prev;
        }

        prev = flatten(root->right, prev);
        prev = flatten(root->left, prev);

        root->right = prev;
        root->left = NULL;
        prev = root;
        return prev;
    }

// using stack
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    if(!root) {
        return NULL;
    }
    
    stack< TreeNode<int>* > st;
    st.push(root);
    
    while( !st.empty() ) {
        TreeNode<int> *curr = st.top();
        st.pop();
        
        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
        
        curr->left = NULL;
        curr->right = ( st.empty() )? NULL : st.top();
    }
    
    return root;
}
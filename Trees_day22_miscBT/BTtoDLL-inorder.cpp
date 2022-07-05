#include<bits/stdc++.h>
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    if(root==NULL) {
        return root;
    }
    
    BinaryTreeNode<int>* dummy = new BinaryTreeNode<int>(-1);
    BinaryTreeNode<int>* temp = dummy;
    
    stack<BinaryTreeNode<int>*> st;
    BinaryTreeNode<int>* node = root;
    st.push(node);
    
    while( !st.empty() ) {
        if(node != NULL) {
            if(node->left != NULL) st.push(node->left);
            node = node->left;
        }
        else {
            node = st.top();
            st.pop();
            
            temp->right = node;
            node->left = temp;
            temp = node;
            
            if(node->right != NULL) st.push(node->right);
            node = node->right;
        }
    }
    
    return dummy->right;
}
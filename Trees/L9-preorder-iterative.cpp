vector<int> getPreOrderTraversal(TreeNode *root) {
    vector<int> ans;
    if(root==NULL) {
        return ans;
    }
    
    stack<TreeNode*> st;
    st.push(root);
    
    while( !st.empty() ) {
        TreeNode* node = st.top();
        st.pop();
        
        ans.push_back(node->data);
        if(node->right != NULL) st.push(node->right);
        if(node->left != NULL) st.push(node->left);
    }
    
    return ans;
}
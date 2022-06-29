vector<int> getInOrderTraversal(TreeNode *root) {
    vector<int> ans;
    if(root==NULL) {
        return ans;
    }
    
    stack<TreeNode*> st;
    TreeNode* node = root;
    st.push(node);
    
    while( !st.empty() ) {
        if(node != NULL) {
            if(node->left != NULL) st.push(node->left);
            node = node->left;
        }
        else {
            node = st.top();
            st.pop();
            
            ans.push_back(node->data);
            
            if(node->right != NULL) st.push(node->right);
            node = node->right;
        }
    }
    
    return ans;
}
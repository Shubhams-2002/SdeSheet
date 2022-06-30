vector<int> getPostOrderTraversal(TreeNode *root) {
    vector<int> ans;
    if(root==NULL) {
        return ans;
    }
    
    stack<TreeNode*> st1;
    stack<int> st2;
    st1.push(root);
    
    while( !st1.empty() ) {
        TreeNode* node = st1.top();
        st1.pop();
        
        st2.push(node->data);
        if(node->left != NULL) st1.push(node->left);
        if(node->right != NULL) st1.push(node->right);
    }

    while( !st2.empty() ) {
        ans.push_back( st2.top() );
        st2.pop();
    }
    
    return ans;
}
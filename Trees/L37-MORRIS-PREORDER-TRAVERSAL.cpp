//MORRIS-PREORDER-TRAVERSAL
vector<int> getPreOrderTraversal(TreeNode *root) {
    vector<int> ans;
    if(!root) return ans;
    
    TreeNode *curr = root;
    while(curr) {
        if(curr->left == NULL) {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else {
            TreeNode *prev = curr->left;
            while(prev->right && prev->right!=curr) {
                prev = prev->right;
            }
            if(prev->right==NULL) {
                prev->right = curr;
                ans.push_back(curr->data);
                curr = curr->left;
            }
            else { //if(prev->right==curr)
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    
    return ans;
}
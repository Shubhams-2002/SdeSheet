//MORRIS-INORDER-TRAVERSAL
vector<int> getInOrderTraversal(TreeNode *root) {
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
                curr = curr->left;
            }
            else { //if(prev->right==curr)
                prev->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    
    return ans;
}
//for right view
void solveRight(TreeNode<int> *root, int level, vector<int>& ans) {
    if(!root) {
        return;
    }
    
    if(level == ans.size()) ans.push_back(root->data);
    solve(root->right, level+1, ans);//first keep going right
    solve(root->left, level+1, ans);
}

//for left view
void solve(TreeNode<int> *root, int level, vector<int>& ans) {
    if(!root) {
        return;
    }
    
    if(level == ans.size()) ans.push_back(root->data);
    solve(root->left, level+1, ans);//first keep going left
    solve(root->right, level+1, ans);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    solve(root, 0, ans);
    return ans;
}
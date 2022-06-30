int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    if(root == NULL) return -1;
    if(root->data==x || root->data==y) {
        return root->data;
    }
    
    int left = lowestCommonAncestor(root->left, x, y);
    int right = lowestCommonAncestor(root->right, x, y);
    if(left == -1) return right;
    if(right == -1) return left;
    
    if(left!=-1 && right!=-1) {
        return root->data;
    }
}
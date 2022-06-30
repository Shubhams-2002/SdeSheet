int heightAndCheck(BinaryTreeNode<int>* root) {
    if(root == NULL) return 0;
    
    int left = heightAndCheck(root->left);
    if(left == -1) return left;
    
    int right = heightAndCheck(root->right);
    if(right == -1) return right;
    
    if( abs(left-right) > 1 ) return -1;
    return max(left, right) + 1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    if( heightAndCheck(root) == -1) return false;
    return true;
}
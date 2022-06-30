int heightAndDiameter(TreeNode<int> *root, int& diameter) {
    if(root == NULL) {
        return 0;
    }
        
    int left = heightAndDiameter(root->left, diameter);
    int right = heightAndDiameter(root->right, diameter);
    diameter = max(diameter, left+right);
    
    return max(left, right) +1;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int diameter;
    heightAndDiameter(root, diameter);
    return diameter;
}

bool isSymmetricHelper(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) 
{
    if(root1==NULL || root2==NULL) {
        return (root1==NULL && root2==NULL) ? true : false;
    }
    
    return (root1->data==root2->data)
        && ( isSymmetricHelper(root1->left, root2->right) )
        && ( isSymmetricHelper(root1->right, root2->left) );
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root) return true;
    return isSymmetricHelper(root->left, root->right);
}

// Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(!node) return;
        
        mirror(node->left);
        Node* leftNode = node->left;
        mirror(node->right);
        Node* rightNode =node->right;
        
        node->left = rightNode;
        node->right = leftNode;
    }
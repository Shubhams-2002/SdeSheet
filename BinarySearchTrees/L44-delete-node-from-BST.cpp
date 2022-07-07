#include <bits/stdc++.h> 
BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key){
    if(!root) return root;
    
    if(root->data == key) {
        if(root->left != NULL) {
            BinaryTreeNode<int>* temp = root->left;
            while(temp->right) temp = temp->right;
            temp->right = root->right;
            root = root->left;
        }
        else root = root->right;
    }
    else if(key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else {
        root->right = deleteNode(root->right, key);
    }
    
    return root;
}
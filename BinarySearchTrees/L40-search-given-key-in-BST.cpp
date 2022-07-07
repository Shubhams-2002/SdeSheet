#include <bits/stdc++.h> 
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *curr = root;
    
    while(curr && curr->data!=x) {
        curr = (curr->data > x)? curr->left : curr->right;
    }
    
    return (curr!=NULL);
}
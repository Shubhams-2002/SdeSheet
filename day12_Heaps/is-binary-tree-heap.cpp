#include<bits/stdc++.h>
int count(struct Node* root) {
    if(root == NULL) return 0;
    
    return 1+count(root->left)+count(root->right);
}

bool isCBT(struct Node* root, int index, int count) {
    if(root == NULL) return true;
    
    if(index >= count) return false;
    else {
        bool l = isCBT(root->left, (2*index)+1, count);
        bool r = isCBT(root->right, (2*index)+2, count);
        
        return (l && r);
    }
}

bool isMaxHeap(struct Node* root) {
    if(root == NULL) return true;
    
    if(root->left == NULL && root->right == NULL) {
        return true;
    }
    if(root->right == NULL) {
        return (root->key > root->left->key);
    }
    else {
        bool l = isMaxHeap(root->left);
        bool r = isMaxHeap(root->right);
        
        return (l && r && root->key > root->left->key && root->key > root->right->key);
    }
    
}


bool isHeap(struct Node* root) {
    return (isCBT(root, 0, count(root)) && isMaxHeap(root));
}
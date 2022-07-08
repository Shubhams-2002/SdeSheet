#include<bits/stdc++.h>
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    //predecessor
    BinaryTreeNode<int>* curr = root;
    int pre = -1;
    while(curr) {
        if(curr->data < key) {
            pre = curr->data;
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
    }
    
    //successor
    curr = root;
    int succ = -1;
    while(curr) {
        if(curr->data > key) {
            succ = curr->data;
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    
    pair<int,int> ans = {pre, succ};
    return ans;
}
#include<bits/stdc++.h>
void changeTree(BinaryTreeNode < int > * root) {
        if(!root) return;

        int children = 0;
        if(root->left) children += root->left->data;
        if(root->right) children += root->right->data;

        if(children < root->data) {
            if(root->left) root->left->data = root->data;
            if(root->right) root->right->data = root->data;
        }

        changeTree(root->left);
        changeTree(root->right);

        int total = 0;
        if(root->left) total += root->left->data;
        if(root->right) total += root->right->data;

        if(root->left || root->right) root->data = total;
}
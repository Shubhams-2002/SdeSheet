#include <bits/stdc++.h> 
int floorInBST(TreeNode<int> * root, int X)
{
    int floor = -1;
    TreeNode<int> *node = root;
    while(node) {
        if(node->val == X) {
            return node->val;
        }
        
        if(X > node->val) {
            floor = node->val;
            node = node->right;
        }
        else {
            node = node->left;
        }
    }
    
    return floor;
}
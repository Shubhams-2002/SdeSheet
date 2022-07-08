#include<bits/stdc++.h>
class node {
public:
    int maxSize;
    int min;
    int max;
    node(int max_size, int _min, int _max) {
        this->maxSize = max_size;
        this->min = _min;
        this->max = _max;
    }
};

node largestBSTHelper(TreeNode<int>* root) {
    if(!root) {
        return node(0, INT_MAX, INT_MIN);
    }
    
    auto left = largestBSTHelper(root->left);
    auto right= largestBSTHelper(root->right);
    
    if(left.max < root->data && root->data < right.min) {
        return node( 1+left.maxSize+right.maxSize,
                    min(left.min, root->data),
                    max(right.max, root->data) );
    }
    else {
        return node( max(left.maxSize,right.maxSize), INT_MIN, INT_MAX );
    }
}

int largestBST(TreeNode<int>* root) 
{
    if(!root) return 0;
    return largestBSTHelper(root).maxSize;
}
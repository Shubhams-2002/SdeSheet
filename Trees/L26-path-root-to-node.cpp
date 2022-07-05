#include<bits/stdc++.h>
bool helper(TreeNode<int>* A, int B, vector<int>& ans) {
    if(!A) return false;
    
    if(A->data == B) {
        ans.push_back(A->data);
        return true;
    }
    
    ans.push_back(A->data);
    if( helper(A->left, B, ans) ) return true;
    if( helper(A->right, B, ans) ) return true;
    
    ans.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    if(!root) return ans;
    helper(root, x, ans);
    return ans;
}
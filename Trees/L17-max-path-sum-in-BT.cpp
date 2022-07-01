//numbers are negative as well as posivtive
class Solution {
public:
    int solve(TreeNode *root, int& ans) {
        if(root == NULL) return 0;
        
        int left = max( 0, solve(root->left, ans) );
        int right = max( 0, solve(root->right, ans) );

        ans = max( ans, left+right+root->val);

        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};

//variaton 
//return -1 if tree has only 1 leaf node
#include<bits/stdc++.h>
int leafCount;
long long int solve(TreeNode<int> *root, long long int& ans) {
    if(root == NULL) return 0;
    //just keep a count of leaf nodes  
    if(root -> left == NULL && root -> right == NULL) leafCount++;
    
    long long int zero = 0;
    long long int left = max( zero, solve(root->left, ans) );
    long long int right = max( zero, solve(root->right, ans) );
    
    ans = max( ans, left+right+root->val);
    
    return max(left, right) + root->val;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    if(root==NULL) return -1;
    
    leafCount = 0;
    long long int ans =0;
    solve(root, ans);
    
    if(leafCount == 1) return -1;
    return ans;
}

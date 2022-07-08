#include<bits/stdc++.h>
class BSTiterator
{
private :
    stack<TreeNode<int>* > st;
    
    void pushAllLeft(TreeNode<int> *root) {
        TreeNode<int> *curr = root;
        while(curr) {
            st.push(curr);
            curr = curr->left;
        }
    }
public :
    BSTiterator(TreeNode<int> *root)
    {
        if(!root) return;
        
        pushAllLeft(root);
    }

    int next()
    {
        TreeNode<int>* node = st.top();
        st.pop();
        
        pushAllLeft(node->right);
        
        return node->data;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};
#include<bits/stdc++.h>
class BSTiterator
{
private :
    stack<BinaryTreeNode<int>* > st;
    bool reverse;
    
    void pushAllLeft(BinaryTreeNode<int> *root) {
        BinaryTreeNode<int> *curr = root;
        while(curr) {
            st.push(curr);
            curr = curr->left;
        }
    }
    
    void pushAllRight(BinaryTreeNode<int> *root) {
        BinaryTreeNode<int> *curr = root;
        while(curr) {
            st.push(curr);
            curr = curr->right;
        }
    }
public :
    BSTiterator(BinaryTreeNode<int> *root, bool rev)
    {
        if(!root) return;
        
        this->reverse = rev;
        if(reverse) pushAllRight(root);
        else pushAllLeft(root);
    }

    int next()
    {
        BinaryTreeNode<int>* node = st.top();
        st.pop();
        
        if(reverse) pushAllRight(node->left);
        else pushAllLeft(node->right);
        
        return node->data;
    }
};

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    BSTiterator l(root, false);
    BSTiterator r(root, true);

    int low = l.next();
    int high= r.next();
    
    while(low < high) {
        if(low + high == k) {
            return true;
        }
        else if(low + high > k) {
            high = r.next();
        }
        else {
            low = l.next();
        }
    }
    
    return false;
}
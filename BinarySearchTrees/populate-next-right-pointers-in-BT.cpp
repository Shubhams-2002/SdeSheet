#include<bits/stdc++.h>
void connectNodes(BinaryTreeNode< int > *root) {
    if(!root) return;
    
    queue< BinaryTreeNode< int >* > q;
    q.push(root);
    
    while( !q.empty() ) {
        int k = q.size();
        
        while(k) {
            k--;
            BinaryTreeNode< int >* node = q.front();
            q.pop();
            
            node->next = k? q.front() : NULL;
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    
}
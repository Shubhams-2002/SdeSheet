#include<bits/stdc++.h>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans ;
    if(root == NULL) return ans;
    vector<int> pre, in, post;
    stack< pair< BinaryTreeNode<int>*, int> > st;
    st.push( {root, 1} );
    
    while( !st.empty() ) {
        auto it = st.top();
        st.pop();
        
        if( it.second == 1) {
                pre.push_back(it.first->data);
                it.second++;
                st.push(it);
                
                if(it.first->left != NULL) {
                    st.push( {it.first->left,1} );
                }
        }
        else if(it.second == 2) {
                in.push_back(it.first->data);
                it.second++;
                st.push(it);
                
                if(it.first->right != NULL) {
                    st.push( {it.first->right,1} );
                }
        }
        else {
                post.push_back(it.first->data);
        }
        
    }
    
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}
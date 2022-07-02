#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(!root) return ans;
    
    queue< pair<TreeNode<int> *, int> > q;
    map<int, int> firstInVertical;
    
    q.push( {root,0} );
    while( !q.empty() ) {
        int k=q.size();
        
        for(int i=0; i<k; i++) {
            auto p = q.front();
            q.pop();
            
            TreeNode<int> *node = p.first;
            if(node->left) q.push( {node->left, p.second-1} );
            if(node->right) q.push( {node->right, p.second+1} );
            if( firstInVertical.count(p.second)==0 ) {
                firstInVertical[p.second] = node->val;
            }
        }
    }
    
    for(auto it : firstInVertical) {
        ans.push_back(it.second);
    }
    
    return ans;
}
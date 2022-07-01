vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL) return ans;
    deque<BinaryTreeNode<int> *> dq;
    
    dq.push_back(root);
    bool rightToLeft = false;
    while( !dq.empty() ) {
        int k = dq.size();
        
        if(rightToLeft) {
            for(int i=0; i<k; i++) {
                BinaryTreeNode<int> *node = dq.back();
                dq.pop_back();
                ans.push_back(node->data);
                
                if(node->right) dq.push_front(node->right);
                if(node->left) dq.push_front(node->left);
            }
        } 
        else {
            for(int i=0; i<k; i++) {
                BinaryTreeNode<int> *node = dq.front();
                dq.pop_front();
                ans.push_back(node->data);
                
                if(node->left) dq.push_back(node->left);
                if(node->right) dq.push_back(node->right);
            }
        }
        
        rightToLeft = !rightToLeft;
    }
    
    return ans;
}

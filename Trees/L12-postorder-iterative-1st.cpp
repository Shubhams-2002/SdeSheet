vector<int> getPostOrderTraversal(TreeNode *root)
{
    TreeNode *curr = root;
    TreeNode *temp;
    stack<TreeNode* > st;
    vector<int> ans;
    
    while( curr!=NULL || !st.empty() ) {
        if(curr!=NULL) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            temp = st.top()->right;
            
            if(temp != NULL) {
                curr = temp;
            }
            else {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                
                while(!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
        }
    }
    
    return ans;
}
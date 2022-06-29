class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;

        queue< TreeNode* > curr_level;
        curr_level.push(root);

        while( !curr_level.empty() ) {
            int k = curr_level.size();
            vector<int> level;

            for(int i=0; i<k; i++) {
                if(curr_level.front()->left != NULL)
                    curr_level.push(curr_level.front()->left);
                if(curr_level.front()->right != NULL)
                    curr_level.push(curr_level.front()->right);

                level.push_back(curr_level.front()->val);
                curr_level.pop();
            }
            
            ans.push_back(level);
        }

        return ans;
    }
};
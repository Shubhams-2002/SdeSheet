class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long int ans=0;
        if(!root) return ans;

        queue< pair<TreeNode*, int> > q;
        q.push({root, 0});

        while ( !q.empty() ) {
            int k = q.size(); 
            int start = q.front().second;
            long int leftMost, rightMost;
            for(int i=0; i<k; i++) {
                TreeNode *node = q.front().first;
                long int index = q.front().second - start;
                cout<<index<<", ";
                q.pop();

                if(i == 0) leftMost = index;
                if(i == k-1) rightMost = index;

                if(node->left) {
                    q.push( {node->left, 2*index+1} );
                }
                if(node->right) {
                    q.push( {node->right, 2*index+2});
                }
            }

            ans = max(ans, rightMost-leftMost+1);
        }

        return ans;
    }
};
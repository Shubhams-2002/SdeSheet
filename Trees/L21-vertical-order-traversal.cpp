//if nodes at same position are to inserted in sorted order then use multiset<int>
// or else 
//If two nodes have the same position, then the value of the node that is added 
//first will be the value that is on the left side, then use vector<int>
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        map< int, map<int, multiset<int> >> lineMap;

        queue< pair<TreeNode*, pair<int,int> > > q;
        q.push( {root, {0,0} } );

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            TreeNode *node = curr.first;
            int line = curr.second.first;
            int level = curr.second.second;
            lineMap[line][level].insert(node->val);

            if(node->left) {
                q.push( {node->left, {line-1, level+1} } );
            }
            if(node->right) {
                q.push( {node->right, {line+1, level+1} } );
            }
        }

        for(auto it : lineMap) {
            vector<int> col;
            for(auto levelMap : it.second) {
                col.insert( col.end(), levelMap.second.begin(), levelMap.second.end() );
            }
            ans.push_back(col);
        }

        return ans;
    }
};
class Solution {
public:
    void s(int idx, int n, int sum, int target,vector<int> &ds, vector<int> &candidates, vector<vector<int>> &ans) {
        if(sum>target) return;
        if(sum==target) {
            ans.push_back(ds);
        }
               
        for(int i=idx; i<n; i++) {
            ds.push_back(candidates[i]);
            sum += candidates[i];
            s(i+1, n, sum, target, ds, candidates, ans);
            ds.pop_back();
            sum -= candidates[i];
            
            while(i<n-1 && candidates[i]==candidates[i+1]) i++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        s(0, candidates.size(), 0, target, ds, candidates, ans);
        
        return ans;
    }
};
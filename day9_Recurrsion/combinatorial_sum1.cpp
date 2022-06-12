class Solution {
public:
    void combSum(vector<int> &arr, int i, int n, int k, vector<vector<int>> &ans, vector<int> &ds) {
    if(i>=n) {
        if(k==0) {
            ans.push_back(ds);
        }
        return;
    }
    
    if(arr[i] <= k) {
        ds.push_back(arr[i]);
        combSum(arr, i, n, k-arr[i], ans, ds);
        ds.pop_back();
    }
    combSum(arr, i+1, n, k, ans, ds);
}
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
    vector<int> ds;
    
    combSum(candidates, 0, candidates.size(), target, ans, ds);
    
    return ans;
    }
};
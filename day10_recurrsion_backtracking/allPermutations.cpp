class Solution {
public:
    void solve1(int idx, int n, vector<int>& nums, vector<int>& ds, vector<vector<int>> &ans, unordered_set<int>& hash) {
        if(idx>=n) {
            ans.push_back(ds);
            return;
        }
        
        for(int i=0; i<n; i++) {
            if(!hash.count(nums[i])) {
                ds.push_back(nums[i]);
                hash.insert(nums[i]);
                solve1(idx+1, n, nums, ds, ans, hash);
                hash.erase(nums[i]);
                ds.pop_back();
            }
        }
    }
    
    void solve(int idx, int n, vector<int>& nums, vector<vector<int>> &ans) {
        if(idx>=n) {
            ans.push_back(nums);
            return;
        }
        
        for(int i=idx; i<n; i++) {
            swap(nums, i, idx);
            solve(idx+1, n, nums, ans);
            swap(nums, i, idx);
        }
    }
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums.size(), nums, ans);
        return ans;
    }
};
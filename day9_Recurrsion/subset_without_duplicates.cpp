class Solution {
public:
    void s(int idx,int n, vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans){
        ans.push_back(ds);
        
        for(int i=idx; i<n; i++) {
            ds.push_back(nums[i]);
            s(i+1, n, ds, nums, ans);
            ds.pop_back();
            
            while(i<n-1 && nums[i]==nums[i+1]) i++;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        s(0, nums.size(), ds, nums, ans);
        return ans;
    }
};
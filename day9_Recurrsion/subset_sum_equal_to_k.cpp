void combSum(vector<int> &arr, int i, int n, int sum, int k, vector<vector<int>> &ans, vector<int> &ds) {
    if(i>=n) {
        if(k==sum && !ds.empty()) {
            ans.push_back(ds);
        }
        return;
    }
    
    ds.push_back(arr[i]);
    sum+=arr[i];
    combSum(arr, i+1, n, sum, k, ans, ds);
    ds.pop_back();
    sum-=arr[i];
    combSum(arr, i+1, n, sum, k, ans, ds);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    combSum(arr, 0, n, 0, k, ans, ds);
    
    return ans;
}
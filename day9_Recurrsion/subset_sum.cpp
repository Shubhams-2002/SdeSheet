void s(int i, int n, int sum, vector<int> &num, vector<int> &ans) {
    if(i==n) {
        ans.push_back(sum);
        return;
    }
    s(i+1, n, sum, num, ans);
    sum += num[i];
    s(i+1, n, sum, num, ans);
    sum -= num[i];
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    s(0, num.size(), 0, num, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
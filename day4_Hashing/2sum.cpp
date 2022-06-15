#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    int n= arr.size();
    vector<vector<int>> ans;
    sort(arr.begin() , arr.end());
    unordered_map<int, int> m;
    
    for(int i=0; i<n; i++) {
        if(m.count(s-arr[i])) {
            for(int j=0; j<m[s-arr[i]]; j++){
                vector<int> a;
                a.push_back(s-arr[i]);
                a.push_back(arr[i]);
                ans.push_back(a);
            }
        }
        m[arr[i]]++;
    }
    sort(ans.begin() , ans.end());
    return ans;
}
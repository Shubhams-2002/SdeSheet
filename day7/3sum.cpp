#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int i=0; i<n-2; i++) {
        int j=i+1, k=n-1;
        while(j<k) {
            if(nums[j] + nums[k] + nums[i] ==0) {
                vector<int> a;
                a.push_back(nums[i]);
                a.push_back(nums[j]);
                a.push_back(nums[k]);
                ans.push_back(a);
                j++;
                while(j<k && nums[j-1]==nums[j]) j++;
                k--;
                while(j<k && nums[k+1]==nums[k]) k--;
            }
            else if(nums[j] + nums[k] + nums[i] <0) {
                j++;
                while(j<k && nums[j-1]==nums[j]) j++;
            }
            else {
                k--;
                while(j<k && nums[k+1]==nums[k]) k--;
            }
        }
        while(i<n-1 && nums[i] == nums[i+1]) i++;
    }
        
    return ans;
    }
};
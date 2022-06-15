#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        int left, right;
        for(int i=0; i<n-3; i++) {
            for(int j=i+1; j<n-2; j++) {
                left=j+1;
                right = n-1;
                
                while(left<right) {
                    if(nums[left]+nums[right] == target-nums[i]-nums[j]) {
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[left];
                        quadruplet[3] = nums[right];
                        ans.push_back(quadruplet);
                        left++;
                        while(left<right && nums[left-1]==nums[left]){
                            left++;
                        }
                        right--;
                        while(left<right && nums[right] == nums[right+1]) {
                            right--;
                        }
                    }
                    else if(nums[left]+nums[right] < target-nums[i]-nums[j]) {
                        left++;
                        while(left<right && nums[left-1]==nums[left]){
                            left++;
                        }
                    }
                    else {
                        right--;
                        while(left<right && nums[right] == nums[right+1]) {
                            right--;
                        }
                    }
                }
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
            while (i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        
        return ans;
    }
};
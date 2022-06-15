#include<bits/stdc++.h>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hash;
        int n= nums.size();
        int max_len=0;
        int curr_len=0;
        
        for(int i=0; i<n; i++) {
            hash[nums[i]] = 0;
        }
        
        for(int i=0; i<n; i++) {
            if(!hash.count(nums[i]-1)) {
                int num = nums[i];
                curr_len=1;
                while(hash.count(num + 1)){
                    num++;
                    curr_len++;
                }
                if(curr_len > max_len) {
                    max_len = curr_len;
                }
            }
        }
        
        return max_len;
    }
};
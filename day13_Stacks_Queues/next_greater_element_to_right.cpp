//code studio, with 1 array
#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> ans(n, -1);
    stack<int> st;
    
    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && arr[i]>=st.top()) {
            st.pop();
        }
        if(!st.empty()) {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    
    return ans;
}

//leetcode, with 2 array
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        unordered_map<int,int> nge;
        stack<int> st;
        
        for(int i=nums2.size()-1; i>=0; i--) {
            while(!st.empty() && nums2[i]>=st.top()) {
                st.pop();
            }
            if(!st.empty()) {
                nge[nums2[i]] = st.top();
            }
            else {
                nge[nums2[i]] = -1;
            }
            st.push(nums2[i]);
        }
        
        for(int i=0; i<nums1.size(); i++) {
            ans[i] = nge[nums1[i]];
        }
        
        return ans;
    }
};
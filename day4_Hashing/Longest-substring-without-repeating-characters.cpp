#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        unordered_set<int> set;
        int max_len=0;
        
        int left=0, right=0;
        while(right < s.length()) {
            if(set.count(s[right])) {
                while(set.count(s[right])) {
                    set.erase(s[left]);
                    left++;
                }
            }
            max_len = max(right-left+1, max_len);
            set.insert(s[right]);
            right++;
        }
        
        return max_len;
    }
    
    int lengthOfLongestSubstring2(string s) {
        int n=s.length();
        int max_len= INT_MIN;
        
        for(int i=0; i<n; i++) {
            unordered_set<int> set;
            for(int j=i; j<n; j++) {
                if(set.count(s[j])) {
                    max_len = max(j-i, max_len);
                    break;
                }
                set.insert(s[j]);
            }
        }
        
        return max_len;
    }
    
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> index;
        int max_len=0;
        
        int left=0, right=0;
        while(right < s.length()) {
            if(index.count(s[right])) {
                if(left <= index[s[right]]) {
                    left = index[s[right]] + 1;
                }
            }
            max_len = max(right-left+1,max_len);
            index[s[right]] = right;
            right++;
        }
        
        return max_len;
    }
};
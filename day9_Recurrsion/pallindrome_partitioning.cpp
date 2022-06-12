class Solution {
public:
    void fun(string s, int idx, vector<vector<string>> &ans, vector<string> &parts) {
        if(idx>=s.size()) {
            ans.push_back(parts);
            return;
        }
        
        for(int i=idx; i<s.size(); i++) {
            if(isPallindrome(s, idx, i)) {
                parts.push_back(s.substr(idx, i-idx+1));
                fun(s, i+1, ans, parts);
                parts.pop_back();
            }
        }
    }
    bool isPallindrome(string s, int start, int end) {
        while(start<=end) {
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans; 
        vector<string> parts;
        fun(s, 0, ans, parts);
        return ans;
    }
};
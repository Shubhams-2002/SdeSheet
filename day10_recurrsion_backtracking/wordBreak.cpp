#include<bits/stdc++.h>
void solve(vector<string> &ans, string &str, string &s, unordered_set<string> &hash, int idx) {
    if(idx>=s.length()){
        ans.push_back(str.substr(1));
        return;
    }
    
    for(int i=idx; i<s.length(); i++) {
        string temp=s.substr(idx, i-idx+1);
        if(hash.count(temp)) {
            string prev=str;
            str += ' ' + temp;
            solve(ans, str, s, hash, i+1);
            str = prev;
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_set<string> hash;
    for(auto it:dictionary) {
        hash.insert(it);
    }
    vector<string> ans;
    string str="";
    solve(ans, str, s, hash, 0);
    return ans;
}
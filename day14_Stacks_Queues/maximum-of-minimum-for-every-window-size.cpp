#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i] ) {
                st.pop();
            }
            if(!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
}
    
vector<int> previousSmallerElement(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i=0; i<n; i++) {
            while(st.top()!=-1 && arr[st.top()] >= arr[i] ) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
}

vector<int> maxMinWindow(vector<int> a, int n) {
        vector<int> next(n);
        next = nextSmallerElement(a);
        
        vector<int> prev(n);
        prev = previousSmallerElement(a);
        
        vector<int> ans(n,INT_MIN);
        
        for(int i=0; i<n; i++) {
            if(next[i]==-1) next[i]=n;
            int width=next[i]-prev[i]-1; // window size
            
            ans[width-1] = max(ans[width-1], a[i]);
        }
        
        for(int i=n-2; i>=0; i--) {
            ans[i] = max(ans[i], ans[i+1]);
        }
        
        return ans;
}
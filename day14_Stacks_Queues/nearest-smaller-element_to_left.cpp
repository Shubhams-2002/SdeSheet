//interviewBit, nearest-smaller-element to left
#include<bits/stdc++.h>
vector<int> Solution::prevSmaller(vector<int> &A) {
    int n=A.size();
    vector<int> ans(n, -1);
    stack<int> st;
    
    for(int i=0; i<n; i++) {
        while(!st.empty() && A[i]<=st.top()) {
            st.pop();
        }
        if(!st.empty()) {
            ans[i] = st.top();
        }
        st.push(A[i]);
    }
    
    return ans;
}

//codeStudio, next_smaller_element_to_right

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> st;
    
    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && arr[i]<=st.top()) {
            st.pop();
        }
        if(!st.empty()) {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    
    return ans;
}
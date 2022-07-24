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

int largestRectangle(vector < int > & heights) {
        int n=heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights);
        
        vector<int> prev(n);
        prev = previousSmallerElement(heights);
        
        int maxArea=0;
        
        for(int i=0; i<n; i++) {
            int l=heights[i];
            if(next[i]==-1) {
               next[i]=n;  
            }
            int b=next[i]-prev[i]-1;
            
            maxArea = max(maxArea, l*b);
        }
        
        return maxArea;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &M, int n, int m){
        int maxArea=largestRectangle(M[0]);
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(M[i][j] != 0) {
                    M[i][j] +=M[i-1][j];
                }
            }
            maxArea = max( maxArea, largestRectangle(M[i]) );
        }
        
        return maxArea;   
}
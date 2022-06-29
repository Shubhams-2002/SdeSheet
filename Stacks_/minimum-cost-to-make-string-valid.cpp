#include<bits/stdc++.h>
int findMinimumCost(string str) {
    if(str.length()%2 == 1) return -1;
    
    stack<char> st;
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        if(ch == '{' ) {
            st.push(ch);
        }
        else {
            if(!st.empty() && st.top() == '{' ) {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
    }
    
    int opn=0, clo=0;
    while(!st.empty()) {
        if(st.top() == '{' ) {
            opn++;
        }
        else {
            clo++;
        }
        st.pop();
    }
    
    int ans = (opn+1)/2 + (clo+1)/2;
    return ans;
}
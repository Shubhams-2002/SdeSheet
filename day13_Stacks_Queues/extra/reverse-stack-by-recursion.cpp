#include<bits/stdc++.h>
void insertAtBottom(stack<int> &st, int element) {
    if(st.empty()) {
        st.push(element);
        return;
    }
    
    int num = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(num);
}

void reverseStack(stack<int> &stack) {
    if(stack.empty()) {
        return;
    }
    
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    
    insertAtBottom(stack, num);
}
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

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    insertAtBottom(myStack, x);
    return myStack;
}

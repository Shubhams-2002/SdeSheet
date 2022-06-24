#include<bits/stdc++.h>
bool isValidParenthesis(string expression)
{
    stack<char> st;
    unordered_map<char,char> brackets;
    brackets['('] = ')';
    brackets['['] = ']';
    brackets['{'] = '}';
    for(int i=0; i<expression.length(); i++) {
        if(brackets.count(expression[i]) ){
            st.push(expression[i]);
        }
        else {
            if(st.empty()) {
                return false;
            }
            else if(expression[i] == brackets[st.top()]) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    if(st.empty()) return true;
    return false;
}
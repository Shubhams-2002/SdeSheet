#include<bits/stdc++.h>
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/' ) {
            st.push(ch);
        }
        else {
            if(ch==')') {
                bool isRedundant = true;
                while(st.top()!='(' ) {
                    char top = st.top();
                    if(top=='+' || top=='-' || top=='*' || top=='/' ) {
                        //not redundant as operator is found between "(" ")"
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant) {
                //if isRedundant has not been made false while in "while loop"
                //it means we reached opening brackets but didn't find any operator
                    return true;
                }
                //stack top contains "(", pop it
                st.pop();
            }
        }
    }
    
    return false;
    //any redundant cases would have returned true
    //completing for loop means no redundant cases found
}

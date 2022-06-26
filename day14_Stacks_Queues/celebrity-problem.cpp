/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
#include<bits/stdc++.h>
int findCelebrity(int n) {
    int a=0, b=n-1;
    
    while(a<b) {
        if( knows(a,b) ) {
            a++;
        }
        else {
            b--;
        }
    }
    
    int candidate = a;
    for(int i=0; i<n; i++) {
        if(i!=candidate && knows(candidate, i) ) {
            return -1;
        }
    }
    for(int i=0; i<n; i++) {
        if(i!=candidate && !knows(i, candidate) ) {
            return -1;
        }
    }
    return candidate;
}
int findCelebrity1(int n) {
    stack<int> st;
    
    for(int i=0; i<n; i++) {
        st.push(i);
    }
    
    while(st.size()>1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        
        if( knows(a,b) ) {
            //since a knows b, a can't be a celebrity
            //but b can be a celebrity
            st.push(b);
        }
        else {
            //since A doesn't know b, A can be a celebrity
            //and since B is not known by A, B can't be a celebrity
            st.push(a);
        }
    }
    
    int candidate = st.top();
    for(int i=0; i<n; i++) {
        if(i!=candidate && knows(candidate, i) ) {
            return -1;
        }
    }
    for(int i=0; i<n; i++) {
        if(i!=candidate && !knows(i, candidate) ) {
            return -1;
        }
    }
    return candidate;
}
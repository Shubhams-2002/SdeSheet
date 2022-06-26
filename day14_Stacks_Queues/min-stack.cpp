#include<bits/stdc++.h>
// Implement class for minStack.
class minStack
{
	long long mini;
    stack<long long> st;
	public:
		
		// Constructor
		minStack() 
		{
            while(!st.empty()) {
                st.pop();
            }
            mini = INT_MAX;
        }
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
            if(st.empty()) {
                st.push(num);
                mini = num;
            }
            else {
                if(num < mini) {
                    st.push(num*2LL - mini);
                    mini = num;
                }
                else {
                    st.push(num);
                }
            }
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
            if(st.empty()) return -1;

            long long t = st.top();
            st.pop();

            if(t < mini) {
                int oldMini = mini;
                mini = 2*mini - t;
                return oldMini;
            }
            return t;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
            if(st.empty()) return -1;
            long long t = st.top();
            if(t < mini) {
                return mini;
            }
            return t;   
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
            if(st.empty()) return -1;
            return mini;
		}
};
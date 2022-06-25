#include<bits/stdc++.h>
class MyQueue {
    stack<int> input;
    stack<int> output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty()) {
            if(input.empty()) return -1;
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int ans = output.top();
        output.pop();
        return ans;
    }
    
    int peek() {
        if(output.empty()) {
            if(input.empty()) return -1;
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return (input.empty() && output.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
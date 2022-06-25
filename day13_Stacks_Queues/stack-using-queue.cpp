#include<queue>
class Stack {
    queue<int> q1;
    queue<int> q2;

   public:
    Stack() {
        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q1.size();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void push(int element) {
        q2.push(element);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        if(q1.empty()) return -1;
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top() {
        if(q1.empty()) return -1;
        return q1.front();
    }
};
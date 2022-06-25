// Stack class.
class Stack {
    int maxSize;
    int* arr;
    int top1;
public:
    
    Stack(int capacity) {
        top1 = -1;
        this->maxSize = capacity;
        arr = new int[capacity];
    }

    void push(int num) {
        if(top1==maxSize-1) {
            return;
        }
        top1++;
        arr[top1] = num;
    }

    int pop() {
        if(top1==-1) {
            return -1;
        }
        int ans = arr[top1];
        top1--;
        return ans;
    }
    
    int top() {
        if(top1==-1) {
            return -1;
        }
        return arr[top1];
    }
    
    int isEmpty() {
        if(top1==-1) {
            return 1;
        }
        return 0;
    }
    
    int isFull() {
        if(top1==maxSize-1) {
            return 1;
        }
        return 0;
    }
    
};
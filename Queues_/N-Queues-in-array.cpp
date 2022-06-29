class NQueue{
    int n, size;
    int* arr;
    int* front;
    int* rear;
    int* next;
    int freespot;
public:
    // Initialize your data structure.
    NQueue(int n, int s){
        this->n = n;
        this->size = s;
        arr = new int[size];
        
        front = new int[n];
        rear = new int[n];
        for(int i=0; i<n; i++) {
            front[i] = -1;
            rear[i] =- 1;
        }
        
        freespot=0;
        next = new int[size];
        for(int i=0; i<size; i++) {
            next[i] = i+1;
        }
        next[size-1] = -1;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        if(freespot == -1) {
            return false;
        }
        
        int index = freespot;
        freespot = next[index];
        if(front[m-1] == -1) {
            front[m-1] = index;
        } 
        else {
            next[rear[m-1]] = index;
        }
        next[index] = -1;
        rear[m-1] = index;
        arr[index] = x;
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        if(front[m-1] == -1) {
            return -1;
        }
        
        int index = front[m-1];
        front[m-1] = next[index];
        
        next[index] = freespot;
        freespot = index;
        
        return arr[index];
    }
};
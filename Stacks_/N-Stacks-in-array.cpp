class NStack
{
    int n, size;
    int* arr;
    int* top;
    int* next;
    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        size = S;
        arr = new int[size];
        
        top = new int[n];
        for(int i=0; i<n; i++) {
            top[i] = -1;
        }
        
        freespot=0;
        next = new int[size];
        for(int i=0; i<size; i++) {
            next[i] = i+1;
        }
        next[size-1] = -1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freespot == -1) {
            return false;
        }
        
        int index = freespot;
        freespot = next[index];
        
        arr[index] = x;
        
        next[index] = top[m-1];
        top[m-1] = index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1] == -1) {
            return -1;
        }
        
        int index = top[m-1];
        top[m-1] = next[index];
        
        next[index] = freespot;
        freespot = index;
        
        return arr[index];
    }
};
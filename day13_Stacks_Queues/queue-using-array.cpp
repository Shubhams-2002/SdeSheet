class Queue {
    int* arr;
    int maxSize=5005;
    int currSize;
    int frnt;
    int rear;
public:
    Queue() {
        arr = new int[maxSize];
        currSize = 0;
        frnt = -1;
        rear = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(currSize == 0) return true;
        return false;
    }

    void enqueue(int data) {
        if(currSize==maxSize){
            return;
        }
        if(rear==-1) {
            frnt = 0;
            rear = 0;
        }
        else {
            rear = (rear+1)%maxSize;
        }
        arr[rear] = data;
        currSize++;
    }

    int dequeue() {
        if(frnt==-1) {
            return -1;
        }
        int ans = arr[frnt];
        if(currSize == 1) {
            frnt = -1;
            rear = -1;
        }
        else{
            frnt = (frnt+1)%maxSize;
        }
        currSize--;
        return ans;
    }

    int front() {
        if(frnt==-1) return -1;
        return arr[frnt];
    }
};
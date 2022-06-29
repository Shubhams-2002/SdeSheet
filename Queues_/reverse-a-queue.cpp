#include<bits/stdc++.h>
//A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
 
// function to create a queue
// of given capacity.
struct Queue* createQueue(unsigned capacity);

// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue);
 
// Queue is empty when size is 0
int isEmpty(struct Queue* queue);
 
// Function to add an item to the queue.
void enqueue(struct Queue* queue, int item);
 
// Function to remove an item from queue.
void dequeue(struct Queue* queue);
 
// Function to get front of queue
int front(struct Queue* queue);

// Function to get size of queue
int size(struct Queue* queue);
*/

//Function to reverse the queue.
struct Queue* rev(struct Queue* Q)
{
    if(size(Q)==1) {
        return Q;
    }
    
    int num = front(Q);
    dequeue(Q);
    
    rev(Q);
    
    enqueue(Q, num);
    
    return Q;
    
    
    // stack<int> st;
    
    // while(!isEmpty(Q)) {
    //     st.push(front(Q));
    //     dequeue(Q);
    // }
    
    // while(!st.empty()) {
    //     enqueue(Q, st.top());
    //     st.pop();
    // }
    
    // return Q;
}
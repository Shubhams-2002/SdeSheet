#include <bits/stdc++.h>

struct Queue* solve(struct Queue *q, int count, int k) {
    if(count==k) {
        return q;
    }
    
    int num=front(q);
    dequeue(q);
    
    solve(q, count+1, k);
    enqueue(q, num);
    
    return q;
}


struct Queue *modifyQueue(struct Queue *queue, int n, int k) {
    
    solve(queue, 0, k);
    
    for(int i=0; i<n-k; i++) {
        enqueue(queue, front(queue));
        dequeue(queue);
    }
    
    return queue;
}
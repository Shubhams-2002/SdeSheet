int kthLargest(vector<int>& arr, int size, int K)
{
    priority_queue<int, vector<int>, greater<int> > min_pq;
    for(int i=0; i<K; i++) {
        min_pq.push(arr[i]);
    }
    for(int i=K; i<size; i++) {
        if(arr[i] > min_pq.top()) {
            min_pq.pop();
            min_pq.push(arr[i]);
        }
    }
    
    return min_pq.top();
}
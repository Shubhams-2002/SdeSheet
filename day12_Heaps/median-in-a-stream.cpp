#include<bits/stdc++.h>
int signum(int num1, int num2) {
    if(num1==num2){
        return 0;
    }
    else if(num1>num2) {
        return 1;
    }
    else {
        return -1;
    }
}

void getMedian(int element, int& median, priority_queue<int>& maxHeap, 
               priority_queue<int, vector<int>, greater<int> >& minHeap) {
    
    switch( signum(maxHeap.size(), minHeap.size()) ) {
        case 0:
            if(element>median) {
                minHeap.push(element);
                median = minHeap.top();
            }
            else {
                maxHeap.push(element);
                median = maxHeap.top();
            }
            break;
        case 1:
            if(element > median) {
                minHeap.push(element);
                median = ( maxHeap.top() + minHeap.top() )/2;
            } 
            else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(element);
                median = ( maxHeap.top() + minHeap.top() )/2;
            }
            break;
        case -1:
            if(element > median) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(element);
                median = ( maxHeap.top() + minHeap.top() )/2;
            }
            else{
                maxHeap.push(element);
                median = ( maxHeap.top() + minHeap.top() )/2;
            }
            break;
    }
}

vector<int> findMedian(vector<int> &arr, int n){
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int median=0;
    vector<int> ans;
    for(int i=0; i<n; i++) {
        getMedian(arr[i], median, maxHeap, minHeap);
        ans.push_back(median);
    }
    return ans;
}

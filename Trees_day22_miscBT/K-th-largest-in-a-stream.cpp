#include<bits/stdc++.h>
class Kthlargest {
    int k;
    priority_queue<int, vector<int>, greater<int> > min_pq;
public:
    Kthlargest(int _k, vector<int> &arr) {
        this->k = _k;
        for(int i=0; i<k; i++) {
            min_pq.push(arr[i]);
        }
    }

    void add(int num) {
        if(num > min_pq.top()) {
            min_pq.pop();
            min_pq.push(num);
        }
    }

    int getKthLargest() {
       return min_pq.top();
    }

};
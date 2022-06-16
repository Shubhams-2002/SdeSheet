#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int> > min_pq;
    for(int i=0; i<k; i++) {
        max_pq.push(arr[i]);
        min_pq.push(arr[i]);
    }
    for(int i=k; i<n; i++) {
        if(arr[i] < max_pq.top()) {
            max_pq.pop();
            max_pq.push(arr[i]);
        }
        if(arr[i] > min_pq.top()) {
            min_pq.pop();
            min_pq.push(arr[i]);
        }
    }
    
    vector<int> ans;
    ans.push_back(max_pq.top());
    ans.push_back(min_pq.top());
    return ans;
}
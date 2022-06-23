#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int> map_count;
    for(int i=0; i<n; i++) {
        map_count[arr[i]]++;
    }
    
    auto comp = [&map_count](int n1, int n2) {
        return (map_count[n1] > map_count[n2]);
    };
    
    priority_queue<int, vector<int>, decltype(comp) > minHeap(comp);
    
    for( pair<int,int> p : map_count) {
        minHeap.push(p.first);
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    vector<int> ans;
    for(int i=0; i<k; i++) {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}
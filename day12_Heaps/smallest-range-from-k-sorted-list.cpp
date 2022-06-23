#include<bits/stdc++.h>
class node {
  public :
    int data;
    int i;
    int j;
    
    node(int val, int i1, int j1){
        this->data = val;
        i = i1;
        j = j1;
    }
};

class compare{
  public:
    bool operator()(node* a, node* b){
        return (a->data > b->data);
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    priority_queue<node*, vector<node*>, compare> minHeap;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0; i<k; i++) {
        minHeap.push( new node(a[i][0], i, 0) );
        maxi = max(maxi, a[i][0]);
        mini = min(mini, a[i][0]);
    }
    int start=mini,end=maxi;
    
    while( !minHeap.empty() ) {
        node* temp = minHeap.top();
        mini = temp->data;
        minHeap.pop();
        if(maxi-mini < end-start) {
            start=mini;
            end=maxi;
        }
        
        if(temp->j + 1 < a[temp->i].size()) {
            minHeap.push(new node(a[temp->i][temp->j+1], temp->i, temp->j+1));
            maxi = max(maxi, a[temp->i][temp->j+1]);
        }
        else {
            break;
        }
    }
    
    return (end - start + 1);
}
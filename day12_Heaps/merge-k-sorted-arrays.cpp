#include<bits/stdc++.h>
class node {
  public :
    int data;
    int i;
    int j;
    
    node(int val, int i1, int j1) {
        this->data = val;
        i = i1;
        j = j1;
    }
};

class compare{
  public:
    bool operator() (node* a, node* b){
        return (a->data > b->data);
        //greater since we need to create a minHeap
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare> minHeap;
    for(int i=0; i<k; i++) {
        node* tmp = new node(kArrays[i][0], i, 0);
        minHeap.push(tmp);
    }
    vector<int> ans;
    while(minHeap.size()>0) {
        node* temp = minHeap.top();
        minHeap.pop();
        ans.push_back(temp->data);
        
        int i = temp->i;
        int j = temp->j;
        if(j+1 < kArrays[i].size()) {
            node* nextFromSameArray = new node(kArrays[i][j+1], i, j+1);
            minHeap.push(nextFromSameArray);
        }
    }
    return ans;
}

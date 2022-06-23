#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    sort(a.begin(), a.end(), greater<int>() );
    sort(b.begin(), b.end(), greater<int>() );
    vector<int> ans;
    
    set< pair<int,int> > s;
    priority_queue< pair<int, pair<int,int> > > maxHeap;
    maxHeap.push( { a[0]+b[0] , {0,0} } );
    s.insert({0,0});
    
    for(int x=0; x<k; x++) {
        pair<int, pair<int,int> > p = maxHeap.top();
        maxHeap.pop();
        ans.push_back(p.first);
        
        int i= p.second.first;
        int j= p.second.second;
        if(i+1<n && !s.count( {i+1,j} ) ) {
            maxHeap.push( {a[i+1] + b[j], {i+1,j} } );
            s.insert({i+1,j});
        }
        if(j+1<n && !s.count( {i,j+1} ) ) {
            maxHeap.push( {a[i] + b[j+1], {i,j+1} } );
            s.insert({i,j+1});
        }
    }
    
    return ans;
}
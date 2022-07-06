#include<bits/stdc++.h>
vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    int n =A.size();
    
    unordered_map<int, int> freq;
    
    int i=0;
    while(i<B-1) {
        freq[ A[i] ]++;
        i++;
    }
    
    i=B-2;
    int j=-1;
    while(i<n-1) {
        i++;
        freq[ A[i] ]++;
        
        ans.push_back(freq.size());
        
        j++;
        freq[ A[j] ]--;
        if(freq[ A[j] ] == 0) {
            freq.erase( A[j] );
        }
    }
    
    return ans;
}

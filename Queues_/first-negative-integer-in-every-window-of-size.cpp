#include <bits/stdc++.h>

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    
    queue<long long int> q;
    vector<long long> ans;
    
    for(long long int i=0; i<N; i++) {
        if(!q.empty() && q.front()==i-K) {
            q.pop();
        }
        
        if(A[i]<0) {
            q.push(i);
        }
        
        if(i>=K-1) {
            if(!q.empty()) {
                ans.push_back(A[q.front()]);
            }
            else {
                ans.push_back(0);
            }
        }
    }
    
    return ans;
}

//Most Optimal
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    vector<long long> ans;
    int firstNegativeIndex = 0;
    
    for(int i = K - 1; i < N; i++)
    {
       
        // skip out of window and positive elements
        while((firstNegativeIndex < i ) &&
              (firstNegativeIndex <= i - K ||
               A[firstNegativeIndex] >= 0))
        {
            firstNegativeIndex ++;
        }
         
        // check if a negative element is found, otherwise use 0
        if(A[firstNegativeIndex] < 0)
        {
            ans.push_back(A[firstNegativeIndex]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    
    return ans;
}
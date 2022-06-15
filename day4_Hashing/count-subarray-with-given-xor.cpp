#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    int prefix_xor=0;
    unordered_map<int, int> visited;
    int n=arr.size();
    int count=0;

    for(int i=0; i<n; i++){
        prefix_xor = prefix_xor ^ arr[i];
        if(prefix_xor == x) {
            count++;
        }
        int h = prefix_xor ^ x;
        if(visited.count(h)) {
            count += visited[h];
        }
        visited[prefix_xor]++;
    }

    return count;
}
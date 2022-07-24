#include<bits/stdc++.h>
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, false);
    vector<bool> curr(k+1, false);
    //base cases
    prev[0] = true;
    if(arr[0] <=k) prev[arr[0]] = true; 
    
    //loops
    for(int i=1; i<n; i++) {
        curr[0] = true; //be careful of this
        for(int j=1; j<=k; j++) {
            bool pick = (arr[i]<=j)? prev[j-arr[i]] : false;
            bool notPick = prev[j];
            
            curr[j] = pick || notPick;
        }
        swap(prev, curr);
    }
    return prev[k];
}
bool canPartition(vector<int> &arr, int n)
{
    int total = 0;
    for(int i=0; i<n; i++) {
        total += arr[i];
    }
    
    if(total%2 == 1) return false;
    //if one subset of sum total/2 is present, 
    //then sum of elements not in subset will alse be equal to total/2
    //since all elements have to be in one partition
    return subsetSumToK(n, total/2, arr);
}

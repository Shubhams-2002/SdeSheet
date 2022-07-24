//Partition a set into two subsets such that the difference of subset sums is minimum.

#include<bits/stdc++.h>
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int total = 0;
    for(int i=0; i<n; i++) {
        total += arr[i];
    }
    vector<bool> prev(total+1, false);
    vector<bool> curr(total+1, false);
    //base cases
    prev[0] = true;
    if(arr[0] <=total) prev[arr[0]] = true; 
    
    //loops
    for(int i=1; i<n; i++) {
        curr[0] = true; //be careful of this
        for(int j=1; j<=total; j++) {
            bool pick = (arr[i]<=j)? prev[j-arr[i]] : false;
            bool notPick = prev[j];
            
            curr[j] = pick || notPick;
        }
        swap(prev, curr);
    }
    
    //now in prev, indices which are equal to subset sum present in set
    // are true
    int mini = INT_MAX;
    for(int s1=0; s1<=total/2; s1++) {
        if(prev[s1]) {
            int s2 = total - s1;
            mini = min( mini, abs(s2-s1) );
            //mini = min( mini, total-(2*s1) );
        }
    }
    return mini;
}
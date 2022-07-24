#include<bits/stdc++.h>
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> prev(tar+1,0);
    vector<int> curr(tar+1,0);
    
    //base cases
    if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
    else prev[0] = 1;  // 1 case - not pick
    
    if(num[0] != 0 && num[0]<=tar) prev[num[0]] = 1; 
    
    int mod = 1e9 + 7;
    //loops
    for(int i=1; i<n; i++) {
        for(int j=0; j<=tar; j++) {
            int pick = (j>=num[i])? prev[j-num[i]] : 0;
            int notPick = prev[j];

            curr[j] = (pick + notPick)%mod;
        }
        prev = curr;
    }
    
    return prev[tar];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int total=0;
    for(int i=0; i<n; i++) total += arr[i];
    
    if(total-d<0) return 0;
    if( (total-d)%2 == 1 ) return 0;
    return findWays(arr, (total-d)/2 );
}



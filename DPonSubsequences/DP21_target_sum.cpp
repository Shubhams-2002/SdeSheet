/*You are given an array ‘ARR’ of ‘N’ integers and a target number, ‘TARGET’. 
Your task is to build an expression out of an array by adding one of the 
symbols '+' and '-' before each integer in an array, and then by concatenating
 all the integers, you want to achieve a target. You have to return the number 
 of ways the target can be achieved.*/

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
int targetSum(int n, int target, vector<int>& arr) {
    int total = 0;
    for(int i=0; i<n; i++) {
        total += arr[i];
    }
    
    if(total < target) return 0;
    if( (total-target) % 2 == 1 ) return 0;
    return findWays(arr, (total-target)/2 );
}

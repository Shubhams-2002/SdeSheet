//another algorithm to find length of LIS 
//For every index i of the array ‘arr’
//dp[ i ] is the length of the LIS that is 
//possible that end with index i of the original array.

//for eg arr[6] = { 5, 4,11, 1,16, 8}
//        dp[6] = { 1, 1, 2, 1, 3, 2}

//dp[0] = 1 = Length of LIS ending with 5 i.e. 5
//dp[1] = 1 = Length of LIS ending with 4 i.e. 4
//dp[2] = 2 = Length of LIS ending with 11 i.e. 5/4,11
//dp[3] = 1 = Length of LIS ending with 1 i.e. 1
//dp[4] = 1 = Length of LIS ending with 16 i.e. 5/4,11,16
//dp[5] = 2 = Length of LIS ending with 8 i.e. 5/4/1,8

//we prefer this dp array because with it we can track
//where length of LIS was increased/updated with the 
//help of a prev_map which will map i to its max LIS 
//so that ith element can be the last element of LIS

//prev_map[0]=-1
//prev_map[1]=-1
//prev_map[2]=1  //before 11 we have 4
//prev_map[3]=-1
//prev_map[4]=2  //before 16 we have 11
//prev_map[5]=3  //before 8 we have 1

//we know LIS at 16(index=4)
//so to print LIS we start from 16 
//and traverse back using prev_map

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n) {
    vector<int> dp(n,1);
    vector<int> prev_map(n,-1);
    
    for(int i=0; i<n; i++) {
        for(int prev=0; prev<i; prev++) {
            
            if(arr[prev] < arr[i]) {
                if(dp[i] < 1+dp[prev]) {
                    dp[i] = 1+dp[prev];
                    prev_map[i] = prev;
                }
            }
            
        }
    }
    
    int ans=1; //length of LIS i.e. 3 above ex
    int last;  //where LIS ends i.e. 16 above ex
    for(int i=0; i<n; i++) {
        if( ans < dp[i] ) {
            ans = dp[i];
            last = i;
        }
    }
    
    vector<int> LIS;
    while(last != -1) {
        LIS.push_back( arr[last] );
        last = prev_map[last];
    }
    reverse( LIS.begin(), LIS.end() );
    
    for(int num : LIS) {
        cout<<num<<", ";
    }
    cout<<endl;
    
    return ans;
}
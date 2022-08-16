/*5,4,11,1,16,8
LIS=>4,11,16
temp=>
5       //initial
4       //replaced
4,11    //pushed back
1,11    //replaced
1,11,16 //pushed back
1,8,16  //replaced

basically find the if back of temp is
greater that arr[i], then find 
lower_bound of arr[i] i.e. position or
index of num equal to or just next greater
*/
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n) {
    vector<int> temp;
    temp.push_back(arr[0]);
    
    int len = 1;
    
    for(int i=1; i<n; i++) {
        if(arr[i] > temp.back()) {
            temp.push_back( arr[i] );
            len++;
        }
        else {
            int index = lower_bound( temp.begin(), temp.end(), arr[i] ) 
                        - temp.begin();
            temp[index] = arr[i];
        }
    }
    
    return len;
}
#include<bits/stdc++.h>
int count(vector<int> &arr, int num) {
    int low=0, high=arr.size()-1;
    while(low<=high) {
       int mid = (low+high)/2;
       if(arr[mid] <= num) {
           low = mid + 1;
       } 
       else {
          high = mid-1;
       }
    }
    return low;
}

int getMedian(vector<vector<int>> &matrix)
{
    int low = 1;
    int high = 1e5;
    int n = matrix.size();
    int m = matrix[0].size();
    while(low<=high) {
        int mid = (low + high)/2;
        int cnt = 0;
        for(int i=0; i<n; i++) {
            cnt += count(matrix[i], mid);
        }
        
        if(cnt <= (n*m)/2) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return low;
}
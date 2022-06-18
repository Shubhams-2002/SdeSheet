#include<bits/stdc++.h>
int searchLeft(vector<int> &A,int low, int high, int B) {
    while(low<=high) {
        int mid = (low+high)/2;
        if(A[mid]==B) return mid;
        else if(A[mid] < B) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return -1;
}

int searchRight(vector<int> &A,int low, int high, int B) {
    while(low<=high) {
        int mid = (low+high)/2;
        if(A[mid]==B) return mid;
        else if(A[mid] < B) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return -1;
}

int peak(vector<int> &A) {
    int low=0, high=A.size()-1;
    
    while(low<=high) {
        int mid = (low + high)/2;
        if(mid>0 && mid<A.size()-1 && A[mid-1]<A[mid] && A[mid+1]<A[mid]) {
            return mid;
        }
        if(A[mid+1]>A[mid]) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return -1;
}

int Solution::solve(vector<int> &A, int B) {
    int peakIndex = peak(A);
    int left = searchLeft(A, 0, peakIndex, B);
    if(left != -1) return left;
    
    return searchRight(A, peakIndex+1, A.size()-1, B);
}

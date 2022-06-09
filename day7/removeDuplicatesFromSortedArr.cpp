#include<bits/stdc++.h>
int removeDuplicates(vector<int> &arr, int n) {
    int i=0;
    for(int j=1; j<n; j++) {
        if(arr[i]!=arr[j]) {
            i++;
            arr[i]=arr[j];
        }
    }
    return i+1;
}
int removeDuplicates1(vector<int> &arr, int n) {
    int i=0,j=0;
    unordered_set<int> set;
    while(j<n) {
        if(set.count(arr[i])) {
            arr[i]=arr[j];
            set.insert(arr[j]);
        }
        else {
            set.insert(arr[i]);
        }
        i++;
        j++;
        while(arr[j-1]==arr[j]) j++;
    }
    return set.size();
}
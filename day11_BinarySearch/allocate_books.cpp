#include<bits/stdc++.h>
bool isPossible(int mid, int days, int chapters, vector<int> &time) {
    int daysUsed=1;
    int timeDecided=0;
    
    for(int i=0; i<chapters; i++) {
        if(timeDecided + time[i] > mid) {
            daysUsed++;
            timeDecided = time[i];
            if(timeDecided > mid) return false;
        }
        else {
            timeDecided += time[i];
        }
    }
    
    if(daysUsed>days) {
        return false;
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{
    if(n>m) return -1;
    int low=time[0];
    int high=time[0]; 
    for(int i=1; i<m; i++) {
        low = min(low, time[i]);
        high += time[i];
    }
    //cout<<low<<" "<<high<<endl;
    int ans;
    while(low<=high) {
        int mid = (low+high)/2;
        //cout<<mid<<" "<<isPossible(mid, n, m, time)<<endl;
        if(isPossible(mid, n, m, time)) {
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    
    return low;
}
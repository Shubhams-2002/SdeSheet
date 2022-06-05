#include <bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt, dt+n);
    //it doesnt matter to us which train is arriving or departing. only thing matters to us is how many platforms are occupied at a given time and we output its max. hence, we traverse through time and so we sort arrays separately
    int count=1;
    int ans=1;
    int i=1,j=0;
    
    while(i<n && j<n) {
        if(at[i]<=dt[j]) { //check if overlap
            count++; //another train occupies(or will need) a platform
            i++; //check with next arrival time
        }
        else {
            count--; // a train leaves a platform empty
            j++; //check with next departure time
        }
        ans = max(ans, count);
    }
    return ans;
}

int calculateMinPatforms1(int at[], int dt[], int n) {
    int ans=0;
    int count;
    
    for(int i=0; i<n; i++) {
        count = 1;
        for(int j=i+1; j<n; j++) {
            if((at[i]>=at[j] && at[i]<=dt[j]) || (at[j]>=at[i] && at[j]<=dt[i])){
                count++;
            }
        }
        ans=max(ans, count);
    }
    return ans;
}
#include <bits/stdc++.h>
struct activity{
    int id;
    int start_time;
    int end_time;
};

bool compare(struct activity a, struct activity b) {
    if (a.end_time == b.end_time) {
        return a.id < b.id;
    }
    else{
        return a.end_time < b.end_time;
    }
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n=start.size();
    struct activity act[n];
    
    for (int i = 0; i < n; i++) {
       act[i].start_time = start[i], act[i].end_time = finish[i], act[i].id = i + 1;
    }
    sort(act, act + n, compare);
    
    int last_finish=act[0].end_time;
    int count=1;
    for(int i=0; i<n; i++) {
        if(last_finish <= act[i].start_time) {
            count++;
            last_finish = max(last_finish, act[i].end_time);
        }
    }
    
    return count;
}
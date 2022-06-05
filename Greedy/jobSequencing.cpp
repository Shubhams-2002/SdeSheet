#include<bits/stdc++.h>
struct job {
    int id;
    int deadline;
    int profit;
};
bool compare(struct job a, struct job b) {
    return (a.profit > b.profit);
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int n=jobs.size();
    struct job j[n];
    for(int i=0; i<jobs.size(); i++) {
        j[i].id=i+1;
        j[i].deadline=jobs[i][0];
        j[i].profit=jobs[i][1];
    }
    sort(j, j+n, compare);
    
    int max_dead=0;
    for(int i=0; i<jobs.size(); i++) {
        max_dead = max(max_dead, jobs[i][0]);
    }
    int time[max_dead+1];
    for(int i=0; i<max_dead+1; i++) {
        time[i]=0;
    }
    for(int i=0; i<jobs.size(); i++) {
        int t = j[i].deadline;
        while(time[t]!=0 && t>0) {
            t--;
        }
        if(t>0) {
            time[t] = j[i].profit;
        }
    }
    int max_profit =0;
    for(int i=1; i<max_dead+1; i++) {
        max_profit += time[i];
    }
    return max_profit;
}

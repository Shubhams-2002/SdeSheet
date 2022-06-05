#include <bits/stdc++.h>
struct meeting{
    int id;
    int start_time;
    int end_time;
};

bool compare(struct meeting a, struct meeting b) {
    if (a.end_time == b.end_time) {
        return a.id < b.id;
    }
    else{
        return a.end_time < b.end_time;
    }
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n=start.size();
    struct meeting meets[n];
    
    for (int i = 0; i < n; i++) {
       meets[i].start_time = start[i], meets[i].end_time = end[i], meets[i].id = i + 1;
    }
    sort(meets, meets + n, compare);

    vector < int > answer;
    answer.push_back(meets[0].id);
    int last_end = meets[0].end_time;
    for (int i = 1; i < n; i++) {
        if(last_end < meets[i].start_time) {
            answer.push_back(meets[i].id);
            last_end = meets[i].end_time;
        }
    }
    //sort(answer.begin(), answer.end());
    
    return answer;
}
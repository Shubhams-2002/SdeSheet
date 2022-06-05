#include <bits/stdc++.h>
struct item {
    int value;
    int weight;
    double ratio;
};

bool compare(struct item a, struct item b) {
    return (a.ratio > b.ratio);
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    struct item its[n];
    for(int i=0; i<n; i++) {
        its[i].weight = items[i].first;
        its[i].value = items[i].second;
        its[i].ratio = (double) items[i].second / (double) items[i].first;
    }
    sort(its, its+n, compare);
    
    int capacity = w;
    int curr_w = 0;
    double profit=0;
    int i=0;
    while(w>0 && i<n) {
        int item_weight_taken = min(its[i].weight, w);
        profit += item_weight_taken*its[i].ratio;
        w = w - item_weight_taken;
        i++;
    }
    
    return profit;
}
#include<bits/stdc++.h>
double p(double x, int n) {
    double ans=1.0;
    for(int i=0; i<n; i++) {
        ans = ans * x;
    }
    return ans;
}
double findNthRootOfM(int n, long long m) {
    double epsilon=1e-7;
    double low=1.0, high =m, mid=0.0;
    while((high-low )> epsilon) {
        mid = (low+high)/2.0;
        if(p(mid,n) > m) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    return low;
}
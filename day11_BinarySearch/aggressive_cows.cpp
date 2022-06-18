#include<bits/stdc++.h>
int chessTournament(vector<int> positions , int n ,  int c){
    sort(positions.begin(), positions.end());
    int low=1, high=positions[n-1];
    int ans;
    
    while(low<=high) {
        int mid = (low+high)/2;
        bool isPossible = false;
        int players = c;
        int lastRoom = positions[0];
        players--;
        for(int i=1; i<n; i++) {
            if(positions[i]-lastRoom >= mid) {
                lastRoom = positions[i];
                players--;
                if(players==0) {
                    isPossible = true;
                    goto label;
                }
            }
        }
        
        label : if(isPossible) {
            low = mid+1;
            ans = mid;
        }
        else {
            high = mid-1;
        }
    }
    
    return ans;
}
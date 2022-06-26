#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    queue<pair<int,int> > rotten;
    int total=0, time=0, cnt=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j]!=0) total++;
            if(grid[i][j]==2) rotten.push({i,j});
        }
    }
    
    int dx[4] = {-1, +1, 0, 0};
    int dy[4] = {0, 0, -1, +1};
    while(!rotten.empty()) {
        int k = rotten.size();
        cnt += k;
        
        while(k) {
            k--;
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();
            
            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1) {
                    grid[nx][ny]=2;
                    rotten.push({nx, ny});
                }
            }
        }
        if(!rotten.empty()) {
            time++;
        }
    }
    
    return (cnt==total)? time : -1;
}
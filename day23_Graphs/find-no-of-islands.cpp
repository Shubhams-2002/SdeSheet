#include<bits/stdc++.h>
void bfs(int x, int y,vector<vector<bool>>& vis, int** arr, int n, int m) 
{
        queue< pair<int, int> > q;
        q.push( {x,y} );
        vis[x][y] = true;
    
    
        int x_dir[8] = {1,-1,0,0,1,1,-1,-1};
        int y_dir[8] = {0,0,1,-1,1,-1,1,-1};
        
        while( !q.empty() ) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int k=0; k<8; k++) {
                int nx = i + x_dir[k];
                int ny = j + y_dir[k];
                
                if(nx>=0 && ny>=0 && nx<n && ny<m 
                   && arr[nx][ny]==1 && !vis[nx][ny]) {
                    q.push( {nx, ny} );
                    vis[nx][ny] = true;
                }
            }
            
        }
}

int getTotalIslands(int** arr, int n, int m)
{
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
        
        int ans=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(arr[i][j]==1 && !vis[i][j]) {
                    bfs(i, j, vis, arr, n, m);
                    ans++;
                }
            }
        }
        
        return ans;
}

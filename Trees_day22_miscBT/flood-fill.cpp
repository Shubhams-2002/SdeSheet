#include<bits/stdc++.h>
class Solution {
public:
    void floodFillDFS(vector<vector<int>>& image, int r, int c,int old, int color) {
        if(image[r][c]==old) {
            image[r][c] = color;
            
            if (r >= 1) floodFillDFS(image, r-1, c, old, color);
            if (c >= 1) floodFillDFS(image, r, c-1, old, color);
            if (r+1 < image.size()) floodFillDFS(image, r+1, c, old, color);
            if (c+1 < image[0].size()) floodFillDFS(image, r, c+1, old, color);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old = image[sr][sc];
        if(old!=color) floodFillDFS(image, sr, sc, old, color);
        return image;
    }
    
//BFS technique gave TIME LIMIT EXCEEDED
vector<vector<int>> floodFillBFS(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        int old = image[sr][sc];
        
        if(old==color) return image;
        
        image[sr][sc] = color;
        queue< pair<int,int> > q;
        q.push( {sr,sc} );
        
        // unordered_set< pair<int,int> > changed;
        // changed.insert( {sr,sc} );
        int dirX[4] = {0,0,+1,-1};
        int dirY[4] = {+1,-1,0,0};
        while( !q.empty() ) {
            int k = q.size();
            
            while(k) {
                k--;
                int x = q.front().first;
                int y = q.front().second;
                
                for(int i=0; i<4; i++) {
                    int nx = x + dirX[i];
                    int ny = y + dirY[i];
                    
                    if(nx>0 && ny>0 && nx<rows && ny<cols && image[nx][ny]==old) {
                        image[nx][ny] = color;
                        q.push( {nx,ny} );
                    }
                }
            }
        }
        
        return image;
    }
};
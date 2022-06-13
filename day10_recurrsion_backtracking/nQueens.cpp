class Solution {
public:
    bool isSafe(int col, int row, int n, vector<string> &board) {
        int duprow = row;
        int dupcol = col;
        
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
              return false;
            row--;
            col--;
        }

        col = dupcol;
        row = duprow;
        while (col >= 0) {
            if (board[row][col] == 'Q')
              return false;
            col--;
        }

        row = duprow;
        col = dupcol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
              return false;
            row++;
            col--;
        }
        
        return true;
    }
    void solve(int col, int n, vector<vector<string>> &ans, vector<string> &board) {
        if(col==n) {
            ans.push_back(board);
            return;
        }
        
        for(int i=0; i<n; i++) {
            if(isSafe(col, i, n, board)) {
                board[i][col] = 'Q';
                solve(col+1, n, ans, board);
                board[i][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s);
        
        solve(0, n, ans, board);
        return ans;
    }
};
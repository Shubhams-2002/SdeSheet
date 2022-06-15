// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void fun(vector<vector<int>> &m, vector<vector<int>> &vis, int n, int i, int j, string s, vector<string> &ans, int di[], int dj[]) {
        if(i==n-1 && j==n-1) {
            ans.push_back(s);
            return;
        }
        string move = "DLRU";
        for(int k=0; k<4; k++) {
            int next_i=i+di[k];
            int next_j=j+dj[k];
            if(next_i>=0 && next_j>=0 && next_i<n && next_j<n && m[next_i][next_j]==1 && vis[next_i][next_j]==0) {
                vis[i][j]=1;
                fun(m, vis, n, next_i, next_j, s+move[k], ans, di, dj);
                vis[i][j]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string s;
        vector<string> ans;
        vector<int> z(n,0);
        vector<vector<int>> vis(n, z);
        int di[] = {1,0,0,-1};
        int dj[] = {0,-1,1,0};
        if(m[0][0]) fun(m,vis,n,0,0,s,ans,di,dj);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
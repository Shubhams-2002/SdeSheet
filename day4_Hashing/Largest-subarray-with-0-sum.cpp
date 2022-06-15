// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> hash; //map with prefix_sum as key and index as value
        int prefix_sum=0;
        int max_len=0;
        for(int i=0; i<n; i++){
            prefix_sum += A[i];
            if(prefix_sum == 0/* && i+1 > max_len*/) {
                if(i+1 > max_len) {
                    max_len = i+1;
                }
            }
            else {
                if(hash.count(prefix_sum)) {
                    if(i-hash[prefix_sum] > max_len) {
                        max_len = i-hash[prefix_sum];
                    }
                }
                else {
                    hash[prefix_sum] = i;
                }
            }
        }
        
        return max_len;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends
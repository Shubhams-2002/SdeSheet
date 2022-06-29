#include<bits/stdc++.h>

class Solution {
	public:
		string FirstNonRepeating(string A){
		    queue<char> q;
		    string ans;
		    vector<int> freq(26, 0);
		    
		    for(int i=0; i<A.length(); i++) {
		        q.push(A[i]);
		        freq[ A[i]-'a' ]++;
				
		        while(!q.empty() && freq[q.front() - 'a']>1) {
		            q.pop();
		        }
		        
		        ans += (q.empty())? '#':q.front();
		    }
		    
		    return ans;
		}

};
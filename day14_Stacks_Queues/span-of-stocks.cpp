#include<bits/stdc++.h>
class StockSpanner {
    stack< pair<int,int> > st;
    int day;
public:
    StockSpanner() {
        st.push({-1,-1});
        day=0;
    }
    
    int next(int price) {
        while(st.top().first!=-1 && st.top().second<=price) {
            st.pop();
        }
        
        int ans = day-st.top().first;
        st.push({day,price});
        day++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
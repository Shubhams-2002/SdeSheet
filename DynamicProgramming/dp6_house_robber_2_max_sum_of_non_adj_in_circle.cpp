#include<bits/stdc++.h>
long long int f(vector<int> &nums){
    int n= nums.size();
    
    long long int prev2 = nums[0];
    long long int prev1 = max(nums[0], nums[1]);
    long long int curr;
    
    for(int i=2; i<n; i++) {
        curr = max(prev1, nums[i] + prev2);
        
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}
//you can also use tabulation or memoization
long long int houseRobber(vector<int>& valueInHouse)
{
    //if houses are in circle and we can't get into adj houses
    //then we can't have last and first houses both in answer
    //since they are adjacent, our answer will have eihter of them
    
    //hence we first solve with first and then with last and return max of them
    //this also helps breaking the circular dependency 
    //and we need to care about adj only
    
    int n= valueInHouse.size();
    if(n==1) return valueInHouse[0];
    
    vector<long long int> dp1(n-1, -1);
    int last = valueInHouse[n-1];
    valueInHouse.pop_back();
    long long int with_first = f(valueInHouse);
    
    vector<long long int> dp2(n-1, -1);
    valueInHouse.push_back(last);
    valueInHouse.erase( valueInHouse.begin() );
    long long int with_last = f(valueInHouse);
    
    return max(with_first, with_last);
}
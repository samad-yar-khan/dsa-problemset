#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int M=prices[n-1];
        int ans = INT_MIN;
        for(int i = n-2 ;i>=0 ;i--){
            ans = max(ans , M-prices[i]);
            M=max(M,prices[i]);
        }
        
        return (ans<0)?0:ans;
    }
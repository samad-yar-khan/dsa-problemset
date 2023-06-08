#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/count-ways-to-build-good-strings/

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long>dp(high+1, 0);
        dp[0] = 1; 
        long long mval = 1e9 + 7;
        for(int i =1;i<=high;i++){
            int c1  = i - zero;
            int c2 = i - one;
            int ans = 0;
            if(c1 >=0 ){
                ans= (ans+ dp[c1])%mval;
            }
            if(c2 >=0 ){
                ans= (ans+dp[c2])%mval;
            }
            dp[i] = ans;
        }
        
        int ans = 0;
        for(int i =low;i<=high;i++){
            ans =(ans + dp[i])%mval;
        }
        return ans;
    }
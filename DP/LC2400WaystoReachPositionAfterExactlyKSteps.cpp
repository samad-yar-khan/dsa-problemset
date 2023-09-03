#include<bits/stdc++.h>
using namespace std;

 long long mval = 1000000007;
    long long rec(int i, int k, int e, vector<vector<int>>&dp){
        if(k<=0){
            return i==e;
        }
        if(abs(i-e)>k || abs(abs(i-e)-k)%2==1){
            return 0;
        }
        if(abs(i-e)==k){
            return 1;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        dp[i][k] = (rec(i+1, k-1,e,dp) + rec(i-1, k-1,e,dp))%mval;
        return dp[i][k];
    }
    int numberOfWays(int startPos, int endPos, int k) {
        
        if(abs(startPos-endPos)>k || abs(k-abs(startPos-endPosk))%2){
            return 0;
        }
        vector<vector<int>>dp(3003, vector<int>(1001,-1));
        vector<int>K(3003,0);
        vector<int>K_1(3003,0);
        startPos+=1000;
        endPos+=1000;
        K_1[startPos]=1;
        for(int i =K+1;i<=k;i++){
            for(int j =0;j<=3003;j++){
                
            }
        }
    }
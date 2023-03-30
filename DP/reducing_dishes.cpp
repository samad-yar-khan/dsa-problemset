#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/reducing-dishes
int sol(vector<int>&s,int ind, int t,vector<vector<int>>&dp){
        
        if(ind >= s.size()){
            return 0;
        }
        
        if(dp[ind][t]!=-1){
            return dp[ind][t];
        }
        
        dp[ind][t] = max(sol(s,ind+1,t,dp),sol(s,ind+1,t+1,dp)+s[ind]*t);
        return dp[ind][t];
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        // vector<vector<int>>dp(satisfaction.size(),vector<int>(satisfaction.size()+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        
        // return sol(satisfaction,0,1,dp);
        int n= satisfaction.size();
        int ans =0;
        int cs =0;
        int ts =0;
        for(int i =n-1;i>=0;i--){
            cs += satisfaction[i];
            ans = max(ans,ts+cs);
            ts+=cs;
        }
        return ans;
    }
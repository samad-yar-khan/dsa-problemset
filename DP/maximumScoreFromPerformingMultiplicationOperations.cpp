#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
int solve(vector<int>& nums, vector<int>& multipliers, vector<vector<int>>&dp, int i,int j, int k){
        if(k>=multipliers.size()){
            return 0;
        }
        if(dp[i][k] != INT_MIN){
            return dp[i][k];
        }
        int case1 = solve(nums,multipliers,dp,i+1,j,k+1) + nums[i]*multipliers[k];
        int case2 = solve(nums,multipliers,dp,i,j-1,k+1) + nums[j]*multipliers[k];
        dp[i][k]= max(case1,case2);
        return dp[i][k];
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
      
        int n = nums.size(), m= multipliers.size();
        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);
        //space optimized DP
        for(int i = m-1 ;i >= 0 ; i--){
            for(int j = i ; j>=0 ; j--){
               
                int ans = max(nums[j]*multipliers[i] + curr[j+1],nums[n-1-(i-j)]*multipliers[i] + curr[j] );
                next[j] = ans;
            }
            curr = next;
            
        }
        // vector<vector<int>> dp(m+1, vector<int>(m+1,INT_MIN));
        // int ans = solve(nums, multipliers, dp, 0, j,0);
        
        return curr[0];
    }
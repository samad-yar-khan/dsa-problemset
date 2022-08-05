#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/combination-sum-iv/submissions/
    int combinationSum4DP(vector<int>& nums,vector<int>&dp, int target) {
        int ans =0;
        if(target == 0){
            return 0;
        }
        if(dp[target]!=-1){
            return dp[target];
        }
        for(int i =0 ;i<nums.size();i++){
            int ta =0;
            if(nums[i] == target){
                ta++;
            }
            if(nums[i]<target){
                 ta = combinationSum4DP(nums,dp,target - nums[i]);
            }
            ans+=ta;
        }
        dp[target] = ans;
        return ans;
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,0);
        for(int i =1;i<=target;i++){
            int ans = 0;
            for(int j =0;j<nums.size();j++){
                if(nums[j] == i){
                    ans++;
                } 
                if(nums[j]<i)
                {
                    ans+=dp[i-nums[j]];
                }
            } 
            dp[i] = ans;
        }
        return dp[target];   
    }

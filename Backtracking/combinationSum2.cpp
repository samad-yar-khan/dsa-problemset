
#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/combination-sum-ii/submissions/

vector<vector<int>> solve(vector<int>&f, int curr, int target){
        if(curr>50){
            vector<vector<int>>ans(0);
            return ans;
        }
        if(target == 0){
            vector<vector<int>>ans(1,vector<int>(0));
            return ans;
        }
        vector<vector<int>> ans(0);
        if(f[curr] == 0){
            return solve(f,curr+1,target);
        }
        for(int i =0;i<=f[curr];i++){
            int subtract = (i)*curr;
            if(subtract <= target){
                vector<vector<int>> ta = solve(f,curr+1,target-subtract);
                for(int j= 0;j<ta.size();j++){
                    vector<int> arr = ta[j];
                    for(int k =0;k<i;k++){
                        arr.push_back(curr);
                    }
                    ans.push_back(arr);
                }
            }
        }
        return ans;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>f(51,0);
        for(int i =0;i<candidates.size();i++){
            f[candidates[i]]++;
        }
        return solve(f,1,target);
        
    }
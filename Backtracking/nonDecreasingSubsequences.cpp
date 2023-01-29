#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long

//https://leetcode.com/problems/non-decreasing-subsequences/
    
void solve(vector<int>& nums, int i, vector<int>&curr, set<vector<int>>&ans){
        
        if(i >= nums.size()){
            if(curr.size()>1){
                ans.insert(curr);
            }
            return;
        }
        
        // in subsequence creation we have two choices, either to add ann elemnt to the current deq or ignore it
        //case1 - ignore
        solve(nums,i+1,curr,ans);
        
        //case2 - see if we can add the number
        
        if(curr.size()==0 || (curr.size()>0 && curr.back()<=nums[i])){
            curr.push_back(nums[i]);// [...]->[... ,x]
            solve(nums,i+1,curr,ans);
            curr.pop_back();//[... ,x] -> [...]   
        }
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>curr;
        set<vector<int>>vecs;
        solve(nums,0,curr,vecs);
        vector<vector<int>>ans;
        for(auto &v:vecs){
            ans.push_back(v);
        }
        return ans;
    }
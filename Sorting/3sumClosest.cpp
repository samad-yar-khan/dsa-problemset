#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/3sum-closest/submissions/
   int threeSumClosest(vector<int>& nums, int target) {
     
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans =-1000000;
        int dev=INT_MAX;
        for(int i =0;i<nums.size();i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k] == target ){
                    return target;
                }else if(nums[i]+nums[j]+nums[k] > target){
                    ans = abs(target-ans) > abs(target-nums[i]-nums[j]-nums[k]) ? nums[i]+nums[j]+nums[k] : ans;
                    k--;
                }else{
                    ans = abs(target-ans) > abs(target-nums[i]-nums[j]-nums[k]) ? nums[i]+nums[j]+nums[k] : ans;
                    j++;;
                }
            }
        }
        return ans;
        
    }
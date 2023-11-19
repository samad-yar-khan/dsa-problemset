#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/

    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int ans =0;
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]){
                ans+=(i+1);
            }
        }
        return ans;
    }
#include<bits/stdc++.h>
using  namespace  std;
//https://leetcode.com/problems/longest-subsequence-with-limited-sum/

 vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<long long>sums(nums.size(),0);
        sums[0] = nums[0];
        for(int i =1;i<nums.size();i++){
            long long a = nums[i];
            sums[i] = sums[i-1] + a;
        }
        vector<int>ans;
        for(int i =0;i<queries.size();i++){
            ans.push_back(upper_bound(sums.begin(),sums.end(),1LL*queries[i])-sums.begin());
        }
        return ans;
    }

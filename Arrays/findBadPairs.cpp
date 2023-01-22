#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-number-of-bad-pairs/submissions/

long long countBadPairs(vector<int>& nums) {
        unordered_map<int,long long>n;
        // n[j] - n[i] = j-i
        // n[j] - j = n[i] -  i -> find these pairs, these wil be pefect pairs and we subtact them from n(n-1)/2
        long long ans =0;
        for(int i =0;i<nums.size();i++){
            int diff = nums[i]-i;
            ans+=n[diff];
            n[nums[i]-i]++;
        }
        long long size = nums.size();
        return (size*(size-1))/2 - ans;
    }

    
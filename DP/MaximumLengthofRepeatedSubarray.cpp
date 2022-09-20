#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
//space optimized dp
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<int>currr(nums2.size()+1);
        vector<int>prev(nums2.size()+1);
        int ans =0;
        for(int i = nums1.size() -1 ;i>=0 ; i--){
            for(int j = nums2.size()-1 ; j>=0;j--){
                int curr = 0;
                if(nums1[i] == nums2[j]){
                    curr+=prev[j+1];
                    curr++;
                }
                currr[j] = curr;
                ans=max(ans,currr[j]);
            }
            prev = currr;
        }
        return ans;
    }
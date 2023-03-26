#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber-ii/

    int rob(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        int n=0,nn=0;
        int a =0;
        for(int  j =nums.size() -2 ;j>=0;j--){
            a = max(nums[j]+nn,n);
            nn =n;
            n =a;
        }
        n=0;
        nn=0;
        int b =0;
        for(int  j =nums.size() -1 ;j>=1;j--){
            b = max(nums[j]+nn,n);
            nn =n;
            n =b;
        }
        return max(a,b);
    }
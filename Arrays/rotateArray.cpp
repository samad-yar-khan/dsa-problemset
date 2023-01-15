#include<bits/stdc++.h>
using namespace std;

/*
n= 7, k = 3
[1,2,3,4,5,6,7]
=> rev whole [7,6,5,4,3,2,1]
=> rev first k [5,6,7,4,3,2,1]
=> rev last n-k [5,6,7,1,2,3,4]
https://leetcode.com/problems/rotate-array/

*/

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k%=n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }

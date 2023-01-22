#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/subarray-sums-divisible-by-k/

// we need to check the places where the remainder is the same and do nc2
// now consider, k=5, a negative remiander like -2 (at index 3) and we have pos remiander lkike 3 at index (8) , them subarray from index 4 to 8 should be divisbke by 5 because (3-(-2) == 5) and remainder with this is zero
//for this reason, we do (sum + k)%k, the exctra k will help us ignore negative values and (-2 + 5)%5 = 3. so the later 3, will match with this anyways and we do a simple  nc2 operation 


    int subarraysDivByK(vector<int>& nums, int k) { 
        
        vector<int>vec(k,0);
        int cs =0;
        int ans =0;
        for(int i =0;i<nums.size();i++){
            cs=((cs+nums[i])%k+k)%k;
            vec[cs]++;
        }
        for(int i =0;i<k;i++){
            ans+=((vec[i])*(vec[i]-1))/2;
        }
        ans+=vec[0];
        return ans;
    }
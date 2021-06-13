/*
https://leetcode.com/problems/first-missing-positive/submissions/
*/

#include <bits/stdc++.h>
using namespace std;

    int firstMissingPositive(vector<int>& nums) {
      
        int n = nums.size();
        int i = 0 ;
        while( i < n){
                
           
            while(nums[i] <= n && nums[i] > 0 && nums[nums[i] -1 ]!= nums[i]){
                int temp = nums[i];
                nums[i] = nums[temp - 1];
                nums[temp-1] = temp ;
            }
            
            i++;
            
        }
        
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != i+1){
                return i+1;
            }
            
        }
        
        return n+1;}
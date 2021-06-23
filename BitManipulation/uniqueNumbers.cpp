/*
https://leetcode.com/problems/single-number/submissions
*/
#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) {
        
        int a = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            a=a^nums[i];    
        }
        
        return a; 
        
    }
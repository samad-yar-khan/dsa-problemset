#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/132-pattern/

    // N2 solution where I maintained a min value and checked for the next two pointers
    bool find132pattern_N2(vector<int>& nums) {
        
        
        int minVal = nums[0];
        for(int i =1;i<nums.size();i++){
            if(nums[i]<minVal){
                minVal = nums[i];
                continue;
            }
            for(int j =i+1;j<nums.size();j++){
                if(nums[j] > minVal && nums[i] >nums[j]){
                    return true;
                }
            }
        }
        return false;
        
        
    }

    //on time
        bool find132pattern(vector<int>& nums) {
        
        
        int third = INT_MIN;
        
        stack<int>s;
        for(int i =nums.size()-1; i>=0 ; i--){
            if(third > nums[i]){
                return true;
            }
            while(s.size()>0 && nums[i] > s.top() ){
                third = max(third,s.top());
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
        
        
        
        
    }
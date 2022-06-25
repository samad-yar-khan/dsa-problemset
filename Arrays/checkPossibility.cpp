#include<bits/stdc++.h>
using namespace std;

bool checkPossibility(vector<int>& nums) {
        int c =0;
        int mn =nums[0];
        for(int i =0;i<nums.size();i++){
           if(mn > nums[i]){
               c++;
           }
               mn = max(nums[i],mn);
           
        }
        int c2 =0;
        
         mn =nums[nums.size()-1];
        for(int i =nums.size()-1;i>=0;i--){
           if(nums[i] > mn){
               c2++;
           }
               mn = min(nums[i],mn);
           
        }
        
        return c<=1 || c2<=1;
    }
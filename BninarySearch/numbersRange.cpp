#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/
 vector<int> searchRange(vector<int>& nums, int target) {
        
        int l=-1;
        int r=-1;
        int n = nums.size();
        int t = target;
        int i =0,j=n-1;
        
        while(i <= j){
            
            int mid = (i+j)/2;
            
            if(nums[mid] == t){
                l=mid;
                j=mid-1;
            }else  if(nums[mid] > t){
                 j=mid-1;
            }else{
              i=mid+1;
            }
            
        }
        i=0;
        j=n-1;
        
        while(i <= j){
            
            int mid = (i+j)/2;
            
            if(nums[mid] == t){
                r=mid;
                i=mid+1;
            }else  if(nums[mid] > t){
                 j=mid-1;
            }else{
              i=mid+1;
            }
            
        }
        
        vector<int>ans;
        ans.push_back(l);
        ans.push_back(r);
        return ans;
    }
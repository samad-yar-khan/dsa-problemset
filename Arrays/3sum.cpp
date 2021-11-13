#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/3sum/submissions/
 vector<vector<int>> twoSum(vector<int> &numbers , int si , int ei , int target){
        
        vector<vector<int>> ans;
        
         int i=si,j=ei;
       
        while(i<j){
            if(target==numbers[i]+numbers[j]){
                vector<int>a;
                a.push_back(-1*target);
                a.push_back(numbers[i]);
                a.push_back(numbers[j]);
               i++;
                j--;
                // cout<<"HEY";
                if(ans.size() == 0){
                    ans.push_back(a);
                }else{
                    if(ans.at(ans.size()-1).at(1) == a[1] && ans.at(ans.size()-1).at(2)==a[2] ){
                         continue;
                    }
                    ans.push_back(a);
                }
            }else if(target < numbers[i]+numbers[j]){
                j--;
            }else{
                i++;
            }
        }
        return ans;
        
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n && nums[i]<=0 ;i++){
            
            vector<vector<int>>a1=twoSum(nums, i+1,n-1,-1*nums[i]);
            if(a1.size()==0){
                continue;
            }
            
            
                for(int j =0;j<a1.size();j++){
                    ans.push_back(a1[j]);
                }
            while(i<n-1 && nums[i]<=0 && nums[i]==nums[i+1]){
                i++;
            }
            
        }
        return ans;
    }
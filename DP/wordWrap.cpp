#include<bits/stdc++.h>
using namespace std;

//word wrap
//https://practice.geeksforgeeks.org/problems/word-wrap1646/1#

//Recursive approach 
//base case : if(we are the last letter , then our ans is zero as we are the last line)
//now we do abcktrackking , we add word, to our line till we reahc the limit and we keep calculating ans ,for diff words insrted ,
//now for eahc i , ther will only be one oprimal ans only ,
//hence to avoid the overllaping subproplems
//we will basiclally add dp and use memeozation

 int solve(vector<int>&nums,int ind , int k,vector<int>&dp){
        if(ind>=nums.size()-1){
            return 0;
        }
        int myAns = INT_MAX;
        int i = ind;
        int curr=k;
        if(dp[ind]!=-1){
            return dp[ind];
        }
        while(i<nums.size() && curr>0){
            curr-=nums[i];
            if(curr<0){
                break;
            }
            if(i==nums.size()-1){
                dp[ind]=0;
                return 0;
            }
            int sa = solve(nums,i+1,k,dp);
            int fSa = (curr*curr)+sa;
            myAns = min(myAns,fSa);
            if(curr!=0){
                curr--;
            }
            i++;
        }
        dp[ind]=myAns;
        return myAns;
    }

    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        //bc
        vector<int>dp(nums.size()+1,-1);
        return solve(nums, 0,k,dp);
    } 

    //pure Dp
    //solution
 int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        //bc
        int n = nums.size();
        if(n==1){
            return 0;
        }
        vector<int>dp(n+1,0);
        int i = n-1;
        while(i >=0 ){
            
            int curr =k;
            int currAns = INT_MAX;
            int j = i;
            while(j<n && curr>=0){
                curr-=nums[j];
                if(curr<0){
                    break;
                }
                if(j==n-1){
                    currAns = 0;
                    break;
                }
                currAns = min(currAns , (curr*curr)+dp[j+1]);
                if(curr!=0){
                    curr--;
                }
                j++;
            }
            dp[i]=currAns;
            i--;
        }
        return dp[0];
       
    } 
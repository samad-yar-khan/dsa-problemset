#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/burst-balloons/

/**
 * 
 * The Logic fo this question is to  us etjhe gap method and see what qwould be my 
 * max cost if i try to dleet a particilaur segment
 * eex we are given [1,3,4,5]
 * so we see the first for intervals of size 1. wohat would be the costopf ddelting 1 from interval [0,0], we also cosndier adjacnet elements
 * d[0][0] = 3
 * dp[i][j] wwill store the max profil we get after burtsing balloons from i to j.
 * 
 * no if we increase gap size to 2
 * we see segment [0,1] , so what would be the profit is 0th ballon is burst at last oout of the sigment. remember, other ars still intact. so this will be 1*4 + dp[1][1] or our second baloon can be the lkast, taht would be cost equal to dp[0][0] +  3*4
 * 
 * 
 * 
 * so inr eahc segmnet , we see what would can be the max cost by choosing once elemnt to be the kast burst baloon
 * 
 */

 int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int gap = 0 ;gap<n;gap++){
            for(int i = 0 ;i+gap<n;i++ ){
              
                for(int j =i;j<=i+gap;j++){
                     int ls = 0, rs =0,left = 1, right =1;
                    if(i-1>=0){
                        left = nums[i-1];
                    }
                    if(i+gap+1<n){
                        right = nums[i+gap+1];
                    }
                    
                    if(j-1>=i){
                        ls = dp[i][j-1];
                    }
                    
                    if(j+1<=i+gap){
                        rs=dp[j+1][i+gap];
                    }
                    
                    dp[i][i+gap] = max(dp[i][i+gap] , left*nums[j]*right + (ls) + (rs));
                    
                }
            }
        }
        
        // for(int i =0;i<n;i++){
        //     for(int j =0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return dp[0][nums.size()-1];
    }
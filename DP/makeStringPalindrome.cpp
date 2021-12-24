#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/


//memoisation

int solve(string &s , int i , int j ,vector<vector<int>>&dp){
        //base case
        if( i >= j){
            return 0;
        }
        int case1 = INT_MAX , case2 = INT_MAX , case3 = INT_MAX;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s.at(i) == s.at(j)){
            case1 = solve(s,i+1,j-1,dp);
        } else{
        
            case2 = solve(s , i+1 ,j,dp) + 1;
            case3 = solve(s ,i,j-1,dp) +1;
            
        }
        
        dp[i][j]= min(case1 , min(case2 , case3));
        return dp[i][j];
    }

    int minInsertions(string s) {
        
        int n = s.length();
        vector<vector<int>> dp(n , vector<int>(n,0));
        
       for(int gap =1 ;gap < n; gap++){
           for(int i = 0 ; i+gap<n  ; i++){
               if(s.at(i) == s.at(i+gap) ){
                   dp[i][i+gap] = dp[i+1][i+gap-1];
               }else{
                   dp[i][i+gap] = min(dp[i+1][i+gap], dp[i][i+gap-1])+1;
               }
           }
       }
        
        // return solve(s,0,n-1,dp);
        return dp[0][n-1];
    }
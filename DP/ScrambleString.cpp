#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/scramble-string/

    bool sol(string &s1, string &s2, int i, int j, int ii, int jj, vector<vector<vector<int>>>&dp){
        
        if(i>j || ii>jj ||  j-i != jj-ii){
            
            return false;
        }
        
        if(i == j){
            return s1[i] == s2[ii];
        }
        
        if(s1.substr(i,j-i+1) == s2.substr(ii, jj-ii+1)){
            return true;
        }
        if(dp[i][j][ii]!=-1){
            return dp[i][j][ii];
        }
        
        
        for(int k=0;k<j-i;k++){
            bool c1 = sol(s1,s2,i,i+k,ii,ii+k,dp) && sol(s1,s2,i+k+1,j,ii+k+1,jj,dp);
            bool c2 = sol(s1,s2,i+k+1,j,ii,ii+j-i-k-1,dp) && sol(s1,s2,i,i+k,ii+j-i-k,jj,dp);
            if(c1||c2){
                dp[i][j][ii] = true;
                return true;
            }
            
        }
         dp[i][j][ii]= false;
        return false;
        
    }
    
    bool isScramble(string s1, string s2) {
        vector<vector<vector<int>>>dp(31,vector<vector<int>>(31,vector<int>(31,-1)));
        int i = 0,ii=0,j=s1.size()-1, jj=s2.size()-1;
        return sol(s1,s2,i,j,ii,jj,dp);
    }
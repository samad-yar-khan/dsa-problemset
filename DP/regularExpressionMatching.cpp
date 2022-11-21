#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/regular-expression-matching/

//memoization
    bool ans(string&s, string&p, int i, int j,vector<vector<int>>&dp){
        if(i>=s.length() || j>=p.length()) {
            if(i==s.length() && j==p.length()){
                return true;
            }
            if(i>=s.length() && j<=p.length()-2 && p[j+1] == '*'){
                return ans(s,p,i,j+2,dp);
            }
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(j==p.length()-1 || p[j+1] != '*' ){
            if(s[i] == p[j] || p[j] == '.'){
                dp[i][j] = ans(s,p,i+1,j+1,dp);
            }else{
                dp[i][j] =false;
            }
            return dp[i][j];
        }
        
        bool zeroChars = ans(s,p,i,j+2,dp);
        if(zeroChars){
            dp[i][j] = true;
            return true;
        }
        
        int x = i;
        while(x<s.length() && (s[x] == p[j] || p[j]=='.')){
            bool sa  = ans(s,p,x+1,j+2,dp);
            if(sa){
                dp[i][j] = true;
                return true;
            }
            x++;
        }
        dp[i][j] =  false;
        return false;       
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length(),vector<int>(p.length(),-1));
        return ans(s,p,0,0,dp);
    }

//tabulation

    bool isMatchDp2(string s, string p) {
       vector<vector<bool>>dp(s.length()+2,vector<bool>(p.length()+2,false));
        dp[s.length()][p.length()] = true;
        for(int j = p.length()-2;j>=0;j--){
            if(p[j+1] == '*'){
                if(j+1 == p.length() -1){
                     dp[s.length()][j]=true;    
                }else{
                     dp[s.length()][j] = dp[s.length()][j+2];     
                }
               
            }
        }
        for(int i =s.length()-1;i>=0;i--){
            for(int j = p.length() -1;j>=0;j--){
                if(j == p.length() - 1 || p[j+1]!='*'){
                    if(p[j]=='.' || p[j] == s[i]){
                        dp[i][j] = dp[i+1][j+1];
                    }else{
                        dp[i][j] = false;
                    }
                }else{
                    dp[i][j] = dp[i][j+2];
                    if(dp[i][j]){
                        continue;
                    }
                    for(int x =i;x<s.length() && (s[x] == p[j] || p[j] == '.');x++){
                        dp[i][j] = dp[x+1][j+2];
                        if(dp[i][j]){
                            break;
                        }
                    }
                }
            }
        }
        
        return dp[0][0];
    }
#include<bits/stdc++.h>
using namespace std;

//the logic casn be a dp logic dp[r][j] will be min(dp[r+1][j],dp[r+1][j+1]) + t[r][j] 
//so to solve the problem we only neeed two array of size n
//hence space of on

int minimumTotal(vector<vector<int>>& triangle) {
       
        int n = triangle.size();
        vector<int>dp1(n,0);
        vector<int>dp2(n,0);
        
        
        for(int i =0;i<n ;i++){
            dp1[i]=triangle[n-1][i];
        }
        
        bool two=true;
        for(int r = n-2;r>=0;r--){
            for(int j =0;j<=r;j++){
                if(two){
                    dp2[j] = min(dp1[j],dp1[j+1])+triangle[r][j];    
                }else{
                    dp1[j] = min(dp2[j],dp2[j+1])+triangle[r][j];  
                }
                
            }
            two = !two;
        }
        
        return two?dp1[0]:dp2[0];
        
        
    }
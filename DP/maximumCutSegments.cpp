#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/cutted-segments1642/1


    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int *dp = new int[n+1];
        for(int i =0 ;i<=n ; i++){
            dp[i] = -1;
        }
        dp[0]=0;
        for(int i = 1 ; i <= n ; i++){
            
            int c1 = -1;
            int c2 = -1;
            int c3 = -1;
            
            if(x<=i){
                c1 = dp[i-x];
            }   
            if(y<=i){
                c2 = dp[i-y];
            }      
            if(z<=i){
                c3 = dp[i-z];
            }   
            
            
            int so = max(c1,max(c2,c3));
            
            dp[i] = (so<0)?so:(so+1);
            
      }
      int ans= dp[n];
      delete [] dp;
      return ans<0?0:ans;
    }
#include<iostream>
using namespace std;

//https://leetcode.com/problems/unique-binary-search-trees/submissions/


int numBSTs(int n,int*dp){
            
        if(n<=1){
            return 1 ;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int ans = 0 ;
        //nodes from the left
        for(int nodes = 1 ; nodes <=n ; nodes++ ){
            ans += (numBSTs(nodes-1,dp)*numBSTs(n-nodes,dp));
        }
        
        dp[n] = ans;
        return ans;
        
    }
    
    int numTrees(int n) {
        int dp[20] ;
        for(int i = 0;i<=n; i++){
            dp[i]=0;
        }
        dp[0] = 1 ;
        dp[1] = 1 ;
        for(int i =  2; i<=n ; i++){
            for(int j = 1 ; j <= i ; j++){
                dp[i] += (dp[j-1]*dp[i-j]);
            }
        }
        int ans = dp[n];
        return ans;
        
    }   
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimum-cost-to-cut-a-stick/submissions/

    int minCostMemo(int n , vector<int>& cuts , int dp[103][103] ,int si , int ei ){
            
        if((ei-si)<=1){
            return 0;
        }
        
        if(dp[si][ei]!=-1){
            return dp[si][ei];
        }
        int smallAns =  INT_MAX;
        for(int i = si+1 ; i < ei ; i++){
            int p1 =  minCostMemo(n,cuts,dp,si,i);
            int p2 =  minCostMemo(n,cuts,dp,i,ei);
            smallAns = min(p1+p2 , smallAns);
        }
        int myAns = smallAns +  cuts[ei]-cuts[si];
        dp[si][ei] = myAns ;
        return myAns;
        
    }
    
    int minCost(int n, vector<int>& cuts) {
                
        int minCutIndex = INT_MAX;
        int maxCutIndex = INT_MIN;
        vector<int> cutsIndex;
        for(int i = 0 ; i  < cuts.size() ; i++){
            minCutIndex=min(minCutIndex,cuts[i]);
            maxCutIndex=max(maxCutIndex,cuts[i]);
            cutsIndex.push_back(cuts[i]);
        }
      
        if(minCutIndex != 0){
            cutsIndex.push_back(0);
        }
        if(maxCutIndex != n){
            cutsIndex.push_back(n);
        }
        
        sort(cutsIndex.begin(), cutsIndex.end());
        int N = cutsIndex.size();
        int dp[103][103];
        for(int i = 0 ; i<N ; i++ ){
            for(int j = 0 ; j <N ; j++){
                dp[i][j] = -1;
            }
        }
        
        int ans = minCostMemo(N,  cutsIndex , dp , 0 , N-1);
        
        
        return ans;      
    }

    //DP
         int minCost(int n, vector<int>& cuts) {
                
        int minCutIndex = INT_MAX;
        int maxCutIndex = INT_MIN;
        vector<int> cutsIndex;
        for(int i = 0 ; i  < cuts.size() ; i++){
            minCutIndex=min(minCutIndex,cuts[i]);
            maxCutIndex=max(maxCutIndex,cuts[i]);
            cutsIndex.push_back(cuts[i]);
        }
      
        if(minCutIndex != 0){
            cutsIndex.push_back(0);
        }
        if(maxCutIndex != n){
            cutsIndex.push_back(n);
        }
        
        sort(cutsIndex.begin(), cutsIndex.end());
        int N = cutsIndex.size();
        int dp[103][103];
        for(int i = 0 ; i<N ; i++ ){
            for(int j = 0 ; j <N ; j++){
                dp[i][j] = 0;
            }
        }
        
        for(int gap = 2 ;  gap < N ; gap++){
            for(int i =0,j=gap ; i <N &&j<N ; i++,j++){
                int ans =INT_MAX;
                for(int k = i+1 ; k<j ;k++){
                    ans=min(ans,dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans+cutsIndex[j]-cutsIndex[i] ;
            }
        }
        
        // int ans = minCostMemo(N,  cutsIndex , dp , 0 , N-1);
        int ans = dp[0][N-1];
        
        return ans;      
    }
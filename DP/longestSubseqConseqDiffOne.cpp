#include<bits/stdc++.h>
using namespace std;


//we basically have to calc the len of longest subseq endig at eahc index
//https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1#
   int longestSubsequence(int N, int A[])
    {
        // code here
        // vector<vector<int>> dp(1001 , vector<int>(1001,-1));
        // return solve(0 , N-1 , A ,0,0,dp);
        int ans = 1 ;
        vector<int> dp(N,1);
        for(int i = 1; i < N ; i++){
            int cnt=0;
            int le = A[i];
            for(int j = i-1; j >=0 ; j-- ){
                if(abs(A[i]-A[j])  == 1){
                    cnt = max(cnt,dp[j]);
                }
            }
            dp[i]+=cnt;
            ans = max(ans , dp[i]);
        }
        return ans;
    }
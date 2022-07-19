#include<bits/stdc++.h>
using namespace std;
//follow gap method , first make a dp where dp[i][j] tells the min changed reqd to maker s(i,j) a palindrom
//now we start forming the dp2[k][i] where it telle the min chanegs reqd to make k palindromic subsctrings of s(i,end)
//https://leetcode.com/problems/palindrome-partitioning-iii/

int palindromePartition(string s, int k) {
        int n = s.length();
        vector<vector<int>>dp1(n,vector<int>(n+1,0));
        for(int i =0;i+1<n;i++){
            dp1[i][i+1] = ( s[i] == s[i+1]) ? 0 : 1;
        }
        for(int gap = 2;gap<n;gap++){
            for(int i=0;i+gap<n;i++)
            {
                dp1[i][i+gap] = dp1[i+1][i+gap-1] + (( s[i] == s[i+gap]) ? 0 : 1);
            }
        }
        vector<vector<int>>dp(k+1,vector<int>(n+1,0));
        for(int i =0;i<n;i++){
           dp[1][i] = dp1[i][n-1];
        }
        for(int K=2;K<=k;K++){
            for(int i =0;i<n;i++){
                int ans=50000;
                for(int j =i;j+1<n;j++){
                    ans = min (ans, dp1[i][j]+dp[K-1][j+1]);
                }
                dp[K][i] = ans;
            }
        }
        return dp[k][0];
    }
#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1/#

int ans(string &a , string &b ,int  i , int j , vector<vector<int>>&dp)
{
    if( i >= a.length() || j>=b.length()){
        return max(a.length()-i  , b.length()-j);
    }
    if(dp[i][j] !=-1){
        return dp[i][j];
    }
    if(a[i]==b[j]){
        return 1 + ans(a,b,i+1,j+1,dp);
    }
    int c1 = 1+ ans(a,b,i+1,j,dp);
    int c2 = 1+ ans(a,b,i,j+1,dp);
    dp[i][j] = min(c1,c2);
    return dp[i][j];
}

int solve(string a, string b) {
    int alen = a.length();
    int blen = b.length();
    vector<vector<int>> dp(alen,vector<int>(blen,-1));
    return ans(a,b,0,0,dp);
}
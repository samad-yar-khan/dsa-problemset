#include<bits/stdc++.h>
using namespace  std;
//https://practice.geeksforgeeks.org/problems/lcs-of-three-strings/0

int lcs(string& a , string& b, string& c,int i , int j , int k,int dp[21][21][21] ){
        
    //base case
    if(i>=a.length() || j >= b.length() || k>=c.length()){
        return 0;
    }
    
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    int ans = 0;
    if(a[i] == b[j] && a[i]==c[k] ){
        int smallAns = lcs(a,b,c,i+1,j+1,k+1,dp) ;
        ans = smallAns + 1 ;
    }else{
        
        int case1 = lcs(a,b,c,i+1,j,k,dp);
        int case2 = lcs(a,b,c,i,j,k+1,dp);
        int case3 = lcs(a,b,c,i,j+1,k,dp);
        
        ans = max(max(case1,case2),case3);
    }
    
    dp[i][j][k] = ans;
    return ans;
    
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    int dp[21][21][21];
    
    for(int i = 0;i<=n1 ; i++){
        for(int j = 0;j<=n2 ; j++){
            for(int k = 0 ; k<=n3 ; k++)
            {
                dp[i][j][k] =-1;
            }
        } 
    }
    
    return lcs(A,B,C,0,0,0,dp);
}
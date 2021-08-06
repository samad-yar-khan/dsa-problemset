#include<bits/stdc++.h>
using namespace std;


// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1
//we calcuate the len of teh square ending at eahc point i,j and tehn clzculate teh max at the end

int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int**dp = new int*[n+1];
        for(int i = 0 ; i <= n ;i++){
            dp[i] = new int [m+1];
            for(int j = 0 ; j<=m ; j++){
                
                dp[i][j] =0 ;
                
            }
        }
        
         int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(mat[i][0] == 1){
                dp[i][0] = 1;
                ans = 1;
            }
        }
        for(int j = 0 ;j< m ; j++){
            if(mat[0][j] == 1){
                dp[0][j] =1 ;
                ans = 1;
            }
        }
       
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m; j++){
                if(mat[i][j] == 1){
                    dp[i][j] = min(dp[i-1][j-1] , min(dp[i-1][j] , dp[i][j-1])) + 1 ;
                    ans = max(dp[i][j] , ans);
                }
            }
        }
        
        for(int i = 0 ; i <= n ; i++){
            delete [] dp[i];
        }
        delete [] dp;
        return ans;
        
    }
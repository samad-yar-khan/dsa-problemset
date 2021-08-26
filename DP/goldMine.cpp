#include<bits/stdc++.h>
using namespace std;

 int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int mat[50][50] ;
        
        for(int i = 0 ; i < n ; i++){
            mat[i][m-1] =M[i][m-1];
        }
        
        for(int j = m-2 ; j>=0 ; j--){
            
            
            
            for(int i = 0 ;i < n ; i++){
                
                int a = INT_MIN , b = INT_MIN , c = INT_MIN;
                
                if(i-1>=0){
                    a=mat[i-1][j+1];
                }
                b=mat[i][j+1];
                if(i+1 < n){
                    c=mat[i+1][j+1];
                }
                
                mat[i][j] = max(a,max(b,c))+M[i][j];
            }
        }
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans,mat[i][0]);
        }
        return ans;
    }
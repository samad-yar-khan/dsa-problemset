#include<bits/stdc++.h>
using namespace std;


//we take a dp atrix such that dp[i][j] signifiees the len of the sq matrix ending at i,j 
//and we just tak ethe maximum at the end

  int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here

        int**dp = new int*[n];
        for(int i = 0 ; i < n ; i++){
            dp[i] = new int[m];
            for(int j = 0 ; j < m ; j++){
                dp[i][j] = 0;
            }
        }

        // for element in row one , and col 1 teh squares ending qt them can be o size of if the elemnt itself is zro else it wll be zro
        //initilaise 1st row and col
        for(int i = 0 ; i < n  ; i++){
            if(mat[i][0] == 1){
                 dp[i][0] = 1;
            }else{
                dp[i][0] = 0 ;
            }
        //len of sq will be 1 if elemnt is one else 0
        }

        for(int j = 0 ; j < m  ; j++){
            if(mat[0][j] == 1){
                 dp[0][j] = 1;
            }else{
                dp[0][j] = 0 ;
            }
        //len of sq will be 1 if elemnt is one else 0
        }

        //now greedy
        for(int i = 1 ; i < n ; i++ ){
            for(int j = 1 ; j < m ; j++){
                if(mat[i][j] == 0){
                    dp[i][j] = 0 ;
                }else{
                    dp[i][j] = min(dp[i-1][j-1]  , min(dp[i-1][j] , dp[i][j-1])) + 1;
                }
            }
        }

        int M= INT_MIN;
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ; j++){
               M =  max(M , dp[i][j]);
            }
        }

         for(int i = 0 ; i < n ; i++){
           delete [] dp[i] ;
           
        }

        delete [] dp;
        return M;
    }
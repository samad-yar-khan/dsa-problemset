#include<bits/stdc++.h>
using namespace std;

bool checkPartitioning(string s) {
        
        //first of all we mark all palindromic subarrays
        bool isPal[2000][2000] ;
        int len = s.length() ; 
        for(int gap = 0 ; gap < len ; gap++){
            
            for(int i = 0 , j = gap ; i<len && j <len ; i++ , j++){
                    
                if(gap==0){
                    isPal[i][j] = true ;
                }else if(gap == 1){
                    isPal[i][j] = (s[i] == s[j]);
                }else {
                        
                    if(s[i] != s[j]){
                        isPal[i][j] = false;
                    }else{
                        isPal[i][j] = isPal[i+1][j-1];
                    }   
                }       
            }
        }

        //now we need to store ans in a dp
        //the rows tell the numner of cuts and 
        //cols tell what index are we on from 0
        //dp[i][j] tells if its possible to partition sting s from 0 to j using i cuts 
        //wehn i =0  , we check if string is palifnrom or no
        //from i = 1 , we start applyihng cuts only if our suffix is a palifdormr
        
        bool dp[3][2000]  ;
        for(int  i = 0; i< 3 ; i++){
            for(int j = 0 ; j < len ; j++){
                dp[i][j] = false;
            }
        }
        
        for(int j = 0 ; j<len; j++){
            if(isPal[0][j]){
                dp[0][j] = true;
            }
        }
        
    
        for(int i = 1 ; i< 3 ; i++){
            for(int j = i; j < len ; j++){
                
                bool ans = false;
                for(int k = j ; k >=i ; k--){
                    
                    if(isPal[k][j]){
                        ans = ans||dp[i-1][k-1];
                    }
                }
                dp[i][j] = ans;
            }
        }
  
    return dp[2][len-1];
        
    }
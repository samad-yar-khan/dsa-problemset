#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/palindrome-partitioning-ii/
    
/*
in this code i am only working on calculating the ans for right if my left portin is a palidnrom

*/

//o(n2)
   bool checkPalindrome(string& s , int si , int ei , bool isPal[2000][2000]){
        
        int i = si ; 
        int j = ei;
        if(s.at(si) != s.at(ei) ){
            return false;
        }
        
        if(s.at(si) == s.at(ei) && ei-si==1){
            return true;
        }

        return isPal[i+1][j-1];
        
        
    }
    
    int solve(string &s , int i , int j , bool isPal[2000][2000] , int dp[2000][2000]){
        
        if(i >= j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(isPal[i][j]){
            return 0;
        }
        
        int ans = INT_MAX;
        for(int itr = i ; itr <= j  ; itr++){
            
          if(isPal[i][itr]){
              int temp = solve(s , itr+1 , j , isPal , dp ) + 1 ;
              ans = min(ans , temp);
          }
            
        }
        
        dp[i][j] = ans;
        
        return ans;
        
    }
    
    int minCut(string s) {
        
        
        int len = s.length();
        
        bool isPal[2000][2000] ;
        for(int i = len-1 ; i>=0 ; i--){
            for(int j = i ; j < len ; j++){
                
                if(i==j){
                    isPal[i][j] = true; 
                }else{
                    isPal[i][j] = checkPalindrome(s , i , j , isPal);
                }   
            }
        }
        
        int dp[2000][2000] ;//will store min cutrs req to make the  palindrom part
        for(int i = 0 ; i < len ; i++){
            for(int j = 0 ; j< len ; j++){
                dp[i][j] = -1;
                if(i==j){
                    dp[i][j] = 0;
                }
            }
        }
        
        int ans= solve(s , 0 , len -1 ,isPal , dp);
        return ans;
        
        
        
        
    }

// O(n3)
int minCut_DP(string s){

 
        
    int len = s.length();

        //i ll start with substring with 0 gap to len -1 gap
    bool isPal[2000][2000];
    // i and j are the indices of two pts on the str
    //store hogya konsa palindropm hai ya nhi
    for(int gap = 0 ; gap < len ; gap++){
        for(int i = 0 ,j = gap ; i < len && j < len; j++ , i++ ){
            if(gap == 0){
                isPal[i][j] = true;
            }else if(gap==1){
                isPal[i][j] = (s[i] == s[j]);
            }else {
                if(s[i]==s[j]){
                    isPal[i][j] = isPal[i+1][j-1];//chota susbtr check karo
                }else{
                    isPal[i][j] = false;
                }
            }

        }
    }   

    int dp [2000][2000];

    for(int gap = 0 ; gap<len ; gap++){
        for(int i = 0 , j= gap ; i<len && j <len ; i++,j++ ){
            if(gap == 0){
                dp[i][j] = 0;
            }else if(gap==1){
                isPal[i][j] = (s[i] == s[j] ? 0 : 1);
            }else {\
                if(isPal[i][j]){
                    dp[i][j] = true;
                }else{
                     int ans = INT_MAX;
                    for(int k = i ; k < j ; k++){
                        ans = min(dp[i][k] , dp[k+1][j] + 1 , ans);
                    }
                    dp[i][j] = ans ;
                }
            }
        } 
    }

    return dp[0][len-1];


}

int minCut_optimised(string s){

    bool isPal[2000][2000];
    int len = s.length();
    for(int gap = 0 ;gap< len ; gap++){

        for(int i = 0 , j = gap ; i < len && j < len  ; i++, j++){

            if(gap == 0){
                isPal[i][j] = true;
            }else if(gap == 1){
                if(s[i] == s[j]){
                    isPal[i][j] = true;
                }else{
                    isPal[i][j] = false;
                }
            }else{

                if(s[i] != s[j]){
                    isPal[i][j] = false;
                }else{
                    isPal[i][j] = isPal[i+1][j-1];
                }
            }
        }
    }

    //now we need to change our approach 
    //wewill opnly work for cased where we have a palendromic suffix 
    /*
        like in partition problem of backtarcking 
        we only cut forther if the current cut was palindrom 
        similiaraly we only get and is our suffix is a palindrome

    */

   int dp[2000] = {0};
   //dp[i] represent the min cuts requrered to make s.substr(0 , i+1) a palindromr
    // for dp[0] ans will be 0 because it is of len 1
    dp[0] = 0;
    // for dp j we will claculate how we can miniomise the cuts by atking precomputed ans for only palidnromic prefexis like in memo method

    for(int j = 1 ; j < len ; j++){

        //check if whoel string is balindrom
        if(isPal[0][j]){
            dp[j] = 0;
        }else{
            //nowe we take palindromic sudffix and calculate answers for them
                int ans = INT_MAX;
            for(int x = j ;  x>=1 ; x--){ //x more tha  one baecasde if x is 0 we get no prefic
                
                if(isPal[x][j]){
                    ans = min(ans, dp[x-1] + 1);
                }
            }
            dp[j] = ans;
        }

      
    }

    return dp[len-1];

}   
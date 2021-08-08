#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/palindrome-partitioning/
    

   void solve(string &s , int i , int j  , vector<string> vec , vector<vector<string>>& ans , bool isPal[17][17]){

        if(i > j){
            ans.push_back(vec);
            return ;
        }

        for(int x = i ; x<=j  ;x++){

            if(isPal[i][x]){    
                vector<string> vec2 = vec;
                vec2.push_back(s.substr(i , x-i+1));
                solve(s , x+1 , j , vec2 , ans , isPal);
            }

        }


    }
    

    bool checkPalindrome(string& s , int si , int ei){
        
       int i = si ; 
        int j = ei;
        
        while(i <= j){
            if(s.at(i)!=s.at(j)){
                return false;
            }
            
            i++;j--;
        }
        
        return true;
        

    }
    vector<vector<string>> partition(string s) {
        
        bool isPal[17][17] ;
        int len = s.length();
        for(int i = 0 ; i<len ; i++){
            for(int j = i ; j < len ; j++){
                
                if(i==j){
                    isPal[i][j] = true; 
                }else{
                    isPal[i][j] = checkPalindrome(s , i , j);
                }
                
            }
        }

        vector<vector<string>> ans;
        vector<string> vec;

        solve(s, 0, len-1 , vec , ans , isPal);
        return ans;
        
        
    }
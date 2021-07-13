// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
  
    pair<int , int> help (string& S , int i , int j ,pair<int , int>** check){
        
        //bc
        if(i==j){
            pair<int , int> p(i,j);
            check[i][j] = p;
            return p;
        }
        
        //check if curr sum is pallandrome
        int i2 = i ;
        int j2 = j ;
        bool isPal=true;
        
        if(check[i][j].first != -1){
            return check[i][j];
        }
        
        while(i2 < j2){
            if(S[i2] != S[j2]){
                isPal = false;
                break;
            }
            i2++;
            j2--;
        }
        
        if(isPal){
            pair<int,int> p(i,j);
            check[i][j] = p;
            return p;
        }
        
      pair<int,int> S1 = help(S,i+1,j , check) ;
      pair<int , int> S2 = help(S,i,j-1 , check);
       
       int diff1 = S1.second - S1.first +1 ;
        int diff2 = S2.second - S2.first +1 ;
       
      if(diff1 > diff2){
            pair<int,int> p(S1.first , S1.second);
            check[i][j] = p;
          return S1;
      }
        pair<int,int> p(S2.first , S2.second);
        check[i][j] = p;
      return S2;
    
    }
    
    string longestPalin (string S) {
        // code here
        pair<int , int> **check = new pair<int , int>*[1001] ;
        
        for(int i = 0 ; i <1001 ; i++){
            check[i] =  new pair<int , int>[1001];
            for(int j = 0 ; j<1001 ;j++){
                check[i][j].first=-1;
                 check[i][j].second=-1;
            }
        }
        
        pair<int , int> p = help(S,0,S.length()-1 , check);
        
         for(int i = 0 ; i <1001 ; i++){
            delete [] check[i];
        }
        delete [] check;
        
        return S.substr(p.first , p.second - p.first+1);
    }
};
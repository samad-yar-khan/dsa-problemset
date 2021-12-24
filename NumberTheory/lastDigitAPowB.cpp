#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/find-last-digit-of-ab-for-large-numbers1936/1#

 int getLastDigit(string a_, string b_) {
        
        
        /*
        UNDERSTAND the pattern of 4
            1   2   3   4   
        2 - 2 , 4 , 8 , 6 , 2
        3 - 3 , 9 , 7 , 1 , 3
        4 - 4 , 6 , 4, 6
        5 - 5
        6 - 6 
        7 - 7 , 9 , 3 , 1 , 7
        8 - 8 , 4 , 2 , 6 , 8
        9 - 9 , 1
        
        so , at mac we can have 4 types of last difits and the pattern return for every 4n powers
        // so we divide the value b and take mod 4 vale of b , becasue we only need the left over 
        if b become s0 , that mean that b is divisble by 4 , in that case our vale should be powered to 4
        and that would be our answer
        
        we chrck exceptions when string b = '0' 
        , and then if b become zero after modulo , it should be 4
        
        */
    
        int b =0;
        
        if(b_.length() == 1 && b_[0] == '0' ){
            return 1;
        }
        int lenB = b_.length();
        for(int i =0; i<lenB ; i++){
            b=((b*10) + (b_[i]-'0'))%4;
        }
        
        int a = a_[a_.length()-1]-'0';
        if(b==0){
            b=4;
        }
        int ans = (pow(a,b));
        ans%=10;
        return ans;
        
        
    }
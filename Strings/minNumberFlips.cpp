#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1

//so e consider boith the cases and see kisko bannae mai min power lagegi

int minFlips (string S)
{
    // your code here
    //eitehr it starts with zeor or its star
    // 0101010
    // 1010101
    
    int case1=0; //01010101
    int case2 =0;///10101010
    
    for(int i =0;i<S.length() ; i++){
        
        if(i%2==0){
            
            if(S[i] == '1'){
                case1++;
            }
            
            if(S[i]== '0'){
                case2++;
            }
            
        }else{
            
            
            if(S[i] == '0'){
                case1++;
            }
            
            if(S[i]== '1'){
                case2++;
            }
            
        }
        
        
    }
    
    return min(case1,case2);
    
}
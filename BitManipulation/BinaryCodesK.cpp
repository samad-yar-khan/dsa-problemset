#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/discuss/2095266/bitmasking-solution-on-c-descriptive

bool hasAllCodes(string s, int k) {
        
        //edge case
        int n = s.length();
        if(n<k){
            return false;
        }
        
        //form a array of size 2^k to mark numbers from 1 to 2^k -1
        vector<bool>present((1<<k),false);
        //if k= 2
        //mask would be 11
        int mask = (1<<k) - 1 ;
        
        //Forming initial  number
        
        //current is our current number
        int curr =0;
        int two = 1;
        for(int i =k-1;i>=0;i--){
            if(s[i]-'0'){
                curr+=two;
            }
            two=(two<<1);
        }
        
        
        if(curr<=mask){
            present[curr] = true;
        }
        
        //sliding window
        for(int i =k;i<n;i++){
          
            curr=curr<<1; //left shift number
            curr=(curr & mask); // mask the overflowing digit at Kth index
            
            if(s[i]=='1'){
                curr= (curr|1);//add 1 to the end if current digit has it
            }
            //mark present if 
            if(curr<=mask){
                present[curr]=true;
            }
        }
        
        //check if all numbers are present
        for(int i =0;i<(1<<k);i++){
            
            if(!present[i]){
                
                return false;
            }
        }
        return true;
        
        
    }
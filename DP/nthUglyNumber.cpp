#include<bits/stdc++.h>
using namespace std;

//  https://leetcode.com/problems/ugly-number-ii/submissions/

  int nthUglyNumber(int n) {
        
        if(n <= 1){
            return n;
        }

        vector<int> ugly(n , 0);
        ugly[0] = 1 ;
        int pointer_2 = 0;
        int pointer_3 = 0;
        int pointer_5 = 0;
        
        for(int i =1 ; i < n ; i++){
            
            int val_2 = ugly[pointer_2]*2;
            int val_3 = ugly[pointer_3]*3;
            int val_5 = ugly[pointer_5]*5;
            int choosen_val = min(val_2 , min(val_3 , val_5));
            
            ugly[i] = choosen_val;
            if(val_2 == choosen_val){
                pointer_2++;
            }
             if(val_3 == choosen_val){
                pointer_3++;
            }
             if(val_5 == choosen_val){
                pointer_5++;
            }
            
            
        }
        return ugly[n-1];
        
    }
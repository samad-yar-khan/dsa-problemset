#include<bits/stdc++.h>
using namespace std;

//  https://leetcode.com/problems/ugly-number-ii/submissions/
// for ugly numebers we need to add numbers which are only multiple of 2 ,3 ,5
//wemust start with 1. now we can ither add 2,3,5
/*
    [1] ans arrau to store all ugly numbers
    p_2=0;
    p_3=0
    p_5=0;

    so inituillay our pointers for 2,3,5 will be at index 0
    no we take min of 2*1 , 3*1 , 5*1 , so we add 2 to our array and increments its pointer  by 1 
    [1,2]
    p_2=1;
    p_3=0
    p_5=0;

    now we have 2*2 , 3*1 , 5*1 , so we add 3 and increment its pointer by 1
    [1,2,3]
    p_2=1;
    p_3=1
    p_5=0;

    now we have 2*2 , 3*2 , 5*1 , so we add 3 and increment its pointer by 1
    [1,2,3,4]
    so we add 4 and incrments 2s pointer
    p_2=2;
    p_3=1
    p_5=0;

    now we get 2*3 , 3*2 , 5*1

    and we add 5 to our array incrmenets its poointer by 1 
    [1,2,3,4,5]
    p_2=2;
    p_3=1
    p_5=1;
*/

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
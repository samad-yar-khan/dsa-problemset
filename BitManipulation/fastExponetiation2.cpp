// https://leetcode.com/problems/powx-n/

#include <iostream>
#define ll long long
#define modVal 1000000007
using namespace std;

    double myPow(double x, int n) {
        
        // we store these values 
        double number = x;
        long long power = n ;
        
        //we just store this bool value to keep a track if our power is negative
        bool isPowerNegative = ( (n<0) ? true : false );
        if( isPowerNegative){
            power= (-1)*power;
        }       
        //how we solve teh qn is that we keep see our power as bbits in binary format
        //if m=3 & n = 5 then => n = 101 >> and 3^5 ==> 3^(bin(101)  ==> 3^(4*1 + 2*0  + 1*1) ==>
        // 3^(4) * 3^(2*0) * 3^(1*1)
        //so at each index of bits , my power of three is swuare and if the bit is set , then
        //we will just multiplye that power to our answer
        double answer = 1 ;
        
        while( power > 0){
                
            if((power&1) > 0)
            {
                answer *=  number;
            }
            
            number*=number; //square 
            power = power>>1; //right shift power
            
        }
        
        //for negative power ans will be 1/ans
        if(isPowerNegative){
            answer = 1/answer;
        }
        
        return answer;
        
        
    }
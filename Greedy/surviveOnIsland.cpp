#include<bits/stdc++.h>
using namespace std;
///https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1#
/*

*/
    int minimumDays(int S, int N, int M){
        // code here
        int survivalDays =  S;
        int perDayNeeds = M ;
        int perDayAccess = N ;
        
        int numSundays = S/7;
        int numBuyingDays = survivalDays-numSundays;
        
        //if the total food  i need is ess than what i can buy over these S days , then i die
        if(numBuyingDays*perDayAccess < perDayNeeds*survivalDays ){
            return -1;
        }
        
        //now i see how many total units i need 
        double totalUnits = survivalDays*perDayNeeds;
        //now we need how many days can we buys this 
        double minDays = totalUnits/double(perDayAccess);
        //now if  we have a decimal that means that we have days is decimal but days musttt be fll
        return ceil(minDays);
    }
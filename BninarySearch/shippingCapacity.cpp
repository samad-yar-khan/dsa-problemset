#include<bits/stdc++.h>
using namespace  std;
//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
 int shippingDays (vector<int>& weights , int capacity){
        
        int days = 1;
        int i=0;
        int currCargo=0;
        while(i < weights.size()){
            
            if(currCargo + weights.at(i) > capacity){
                days++;
                currCargo =   weights.at(i);
            }else{
                 currCargo +=   weights.at(i);
            }
            i++;
            
        }
        return days;
        
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int totalWt = 0 ;
        int maxWt = 0;
        
        for(int i =0;i < weights.size() ; i++){
            totalWt+=weights[i];
            maxWt = max(maxWt , weights[i]);
        }
        
        //binary search
        //search space - maxWt to totalWt;
        
        int si = maxWt ;//we need to transfer the max wiedhed item
        int ei = totalWt ;
        int ans =  totalWt;
        
        while(si <= ei){
            
            int mid = si  + ((ei-si)/2);
            int daysTaken = shippingDays(weights,mid);
            if( daysTaken > days ){
                si=mid+1;//we need to increase the capacity
            }else{
                ans = min(ans ,mid);
                ei = mid-1;//decrease the capacity
            }
        }
        return ans;
        
    }
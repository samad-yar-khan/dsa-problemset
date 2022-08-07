#include<bits/stdc++.h>
using namespace std;


//https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1#
  
    bool isPossible(int arr[] , int n , int k , long long t){
        //tells is its posible o pppaint this by k ainters if none takes more than t time
        
        long long totalTime =  0 ;
        
        int painters = 1;
        for(int i = 0 ;  i < n ; i++){
            if(totalTime + arr[i] > t){
                totalTime = arr[i];
                painters++;
                if(painters > k){
                    return false;
                }
            }else{
                totalTime += arr[i];
            }
        }
        return  true;
            
    }

//basically we need to find the mintme reqired to pant the wood peices if the painters start simultaionusly
//we do this like the book allocation pprblen
//either we can  aint int 0 time or we caan have one painter paaint all the items
//so we have a monotonic increeasin seq , mid = (maxLengh + sumLen)/2 
//if k painterd sof less can print in mid time each , then we are gododo to go and we store ans and mid 
//and look to minimise our time and do ei =mid
//if we need more painter s, then we need to increae the reqd time and do  si=mid + 1
//hencein this manner we go and find the asn

    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        long long sumLength=0;
        int maxLength = 0;
        
        for(int i = 0 ; i < n ; i++){
            maxLength = max(maxLength , arr [i]);
            sumLength+=arr[i];
        }
        
        
        
        long long si = maxLength ; //jitna time lagega max length ki lakdi print karne mai uss ekam lag hi nhi skata
        long long ei = sumLength;
        long long ans = 0 ;
        
        while(si <= ei){
            
            long long maxPaintTime = si + (ei-si)/2;///mid
            
            if(isPossible(arr , n , k ,maxPaintTime)){
                ei=maxPaintTime-1;
                ans = maxPaintTime;
            }else{
                si=maxPaintTime+1; //we need more thime
            }
            
        }
        
        return ans;
    }
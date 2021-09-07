#include<bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#

/*
Solution Using Bit Manipulation - We mark the number of set bits at each position and at the end we get an array which has the freq of set set bits at each position , now we consider those set positions where the number of set bits is more than n/2 and form our number , now we iterate through the array and see if our formed integer has a freq more than n./2 or not . if it does then we return the number else we return -1
*/

 int majorityElement(int a[], int size)
    {
        
        //represenet a 18 bit int
        int arr[18] = {0};
        
        
        //count freq of set bits at each posn
        for(int i = 0 ;  i < size ; i++){
        
            int A = a[i] ;
            int j = 0;
            while(A > 0){
                
                if(A&1){
                    arr[j]++;
                }
                A=A>>1;
                j++;
            }
            
        }
        int  ans =0;
    
        //form a number by seetting bits at the posns where teh set bits is more than n+1/2
        for(int i=0 ; i<18 ; i++){
            if(arr[i] > size/2){
                ans = ans + (1<<i);
            }        
        }
        
        int count =0;
        //count the freq of the number formed 
        for(int i = 0 ; i< size ; i++ ){
            if(a[i] == ans){
                count++;
            }
        }
        
        //if count is more than  n/2 we got an ans;
        if(count>(size/2)){
            return ans;
        }
        //no ans
        return -1;
    }
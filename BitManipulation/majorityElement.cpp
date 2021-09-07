#include<bits/stdc++.h>
using namespace std;

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
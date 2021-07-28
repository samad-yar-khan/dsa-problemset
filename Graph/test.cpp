#include <bits/stdc++.h>
using namespace std;

#define MULTIPLY(a, b) a*b

int getMinDiff(int arr[], int n) {
      
        //dvivide our array into two parts
        // from left hart we add k and right half we subtract k ,
        // the  get the extremes from both the arrays and calculate diff 
        // if diff is lessr than replace min and max 
        sort(arr,arr+n);
        int tMin = arr[0]   ;
        int tMax = arr[n-1]  ;
        
        
        int i = 0 ;
        while(i < n-1){
                

            int leftMin = arr[0];
            int leftMax = arr[i];

            if(leftMin&1){
                leftMin*=2;
            }

            if(leftMax&1){
                leftMax*=2;
            }
           
            
            int rightMin = arr[i+1];
            int rightMax = arr[n-1];

            if(!(rightMax&1)){
                rightMax/=2;
            }

            if(!(leftMax&1)){
                leftMax/=2;
            }
            int minHere = min(min(leftMin , leftMax) , min(rightMin , rightMax));
            int maxHere = max(max(leftMin , leftMax) , max(rightMin , rightMax));           
            
            if(maxHere - minHere < tMax - tMin ){
                tMax = maxHere;
                tMin = minHere;
              
            }
            i++;
            
        }
        
        return tMax-tMin;
    }

    int main(){

        int T= 0;
        cin>>T;
        for(int i = 0 ; i <T ; i++){
            int n = 0 ;
            cin>>n ; 
            int *arr = new int [n];
            for(int i= 0; i <n  ; i++){
                cin>>arr[i];
            }
            cout<<getMinDiff(arr , n)<<"\n";


            delete [] arr;
        }
    }
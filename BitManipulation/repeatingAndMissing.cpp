#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#
/*
We solve ths question like how we solve a qn where we have two unique numbers and othe rdublicates in an array and we have to find teh two uniques. For this we need to onsider the case of 1 2 3 3 5 , here 4 is missing and 3 s repeating and in an ideal case it woul d be 1 2 3 4 5 , if we combine thie we get - [1 2 3 4 5 ][ 1 2 3 3 5] , if we take xor off this whole we get 3^4 , so it feel like to our xor the double 3s sont exixts and to the or its the same qn . now we have A^B , now we need to check the first set bit in A^B as that will be unique to A or B , here we get firts set bit at pos 0   , so our mask is 00000001 ie 1 , now we take the xor of alll aalents from [1 2 3 4 5] and our original [1 2 3 3 5] , who have this bit set . so we get 1 ^ 3^ 5 ^1^3^3^5 = 3 , the double 3s cnacel out and we get our unique elemet . no we find the next unie by just joing a cor of 3 with A^B , and now the one which is in the oriinal array wil be the repeate and he otther would be the missing 
*/
 int *findTwoElement(int *arr, int n) {
        // code here
        int *ans = new int[2];
        
        int xorAB = 0;
        for(int i = 1 ; i <= n ; i++){
            xorAB = xorAB ^ i; //1^2^3^4^5
        }
        for(int i = 0 ;i<n ; i++){
            xorAB = xorAB^arr[i];
        }
        
        // cout<<xorAB<<" ";
        //find firts set but in xor aab as that will be unique to only one of ab
        int c = 0;
        int t = xorAB;
        // cout<<t<<" ";
        int one=1;
        while((t&one)!=one){
            c++;
            t=t>>1;
        }
        // cout<<c<<" ";
        int setBit = 1<<c;
        // cout<<setBit<<" ";
        //now we go trhough all 
        //1 2 3 4 5 1 2 3 3 5 
        //and take values where this bit is set
        int A = 0;
        for(int i = 1 ; i <= n ; i++){
           if((i&setBit) > 0){
            //   cout<<i<<" ";
              A = A^i;
           }
        }
        
        for(int i = 0 ; i <n ; i++){
            if((arr[i] & setBit) > 0){
                // cout<<arr[i]<<" ";
                A=A^arr[i];
            }
        }
       
        //1 1 3 3 3 5 5 =  3 
      
        int B=xorAB^A;
        //   cout<<A<<" "<<B<<" ";
        for(int i = 0 ; i < n ; i++){
            int c=B^arr[i];
            if( c == 0){
                // cout<<c<<"c"<<arr[i]<<"h";
                int temp = A;
                A=B;
                B=temp;
                break;
            }
        }
        ans[0]  = A;
        ans[1] = B;
        return ans;
        
    }

     int *findTwoElement(int *arr, int n) {
        // code here
        int *ans = new int[2];
        
        int xorAB = 0;
        for(int i = 1 ; i <= n ; i++){
            xorAB = xorAB ^ i; //1^2^3^4^5
        }
        for(int i = 0 ;i<n ; i++){
            xorAB = xorAB^arr[i];
        } 
        //find firts set but in xor aab as that will be unique to only one of ab
        int c = 0;
        int t = xorAB;
        // cout<<t<<" ";
        int one=1;
        while((t&one)!=one){
            c++;
            t=t>>1;
        }
        int setBit = 1<<c;
    
        //now we go trhough all 
        //1 2 3 4 5 1 2 3 3 5 
        //and take values where this bit is set
        int A = 0;
        for(int i = 1 ; i <= n ; i++){
           if((i&setBit) > 0){
              A = A^i;
           }
        }
        
        for(int i = 0 ; i <n ; i++){
            if((arr[i] & setBit) > 0){
                A=A^arr[i];
            }
        }
       
        int B=xorAB^A;
       
        for(int i = 0 ; i < n ; i++){
            int c=B^arr[i];
            if( c == 0){
               
                int temp = A;
                A=B;
                B=temp;
                break;
            }
        }
        ans[0]  = A;
        ans[1] = B;
        return ans;
        
    }
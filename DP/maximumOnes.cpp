#include<bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1

 // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int k) {
        // code here
     vector<int> left;// one he elft of a[i]
   
     vector<int> indexOfZero;
     int mxRange=0;
     int c1 =0;
     for(int i =0;i < n ; i++){
            if(arr[i] == 1){
                c1++;
            }else{
                left.push_back(c1);
                mxRange = max(mxRange,c1);
                // cout<<c1<<" ";
                c1=0;
            }
     }
     
    vector<int> right(left.size(),0);//one to the right of a[i] 
    int c2=0;
    int j=left.size()-1;
    for(int i =n-1;i >=0 ; i--){
        
         if(arr[i] == 1){
                c2++;
            }else{
                //   cout<<c2<<" ";
                  mxRange = max(mxRange,c2);
                right[j--] = c2;
            c2=0;
        }        
           
    }
    if(k==0){
        return mxRange;
    }
    if(left.size() <= k){
        return n;
    }
     
    int w1 = 0 ;
    int w2 = 0;
    int ans =0;
    while(w2<right.size() && w2<k){
       ans+=left[w2];
       ans++;
       if(w2 == k-1){
           ans+=right[w2];
       }
        w2++;
    }
  
    int A=ans;
    while(w2<right.size()){
        
        int ans2 = ans-left[w1]-1;
       
        
        ans2 += (right[w2]+1);
        A=max(A,max(ans,ans2));
        ans = ans2;
        w1++;
        w2++;
        
    }
    return A;
     
     
     
     
    }  
#include<bits/stdc++.h>
using namespace std;

//brute force 2^n
int lis(int n, int a[] ,int vecLen , int maxE){
        //base case
    if(n==0){
      return vecLen;
    }
       
       
    if( a[0] > maxE ){
            
        return max(lis(n-1 ,a+1, vecLen + 1 , a[0])  , lis(n-1 ,a+1, vecLen, maxE) );
            
    }
            
    return max( lis(n-1 ,a+1, vecLen, maxE) ,  lis(n-1 ,a+1, 1, a[0]));
           
       
       
} 
    
    
int longestSubsequence(int n, int a[]){
   // your code here
   return lis(n,a,0,-1);
}

//dp n2
int lis_dp(int n, int a[]){

    int*lis_at_index=new int[n+1];
    for(int i = 0 ; i <= n ; i++){
        lis_at_index[i] = 1;
    }


    for(int i = 1 ; i  < n ; i++){

        int myNumber = a[i];

        sort(a , a+i);
     
        for(int j = i ; j >= 0 ; j--){

            int*ub = upper_bound(a , a+i , a[i]);

            if(a[j] < a[i]){
                lis_at_index[i] = max(lis_at_index[i] , lis_at_index[j] + 1);
            }

        }

    } 

    int maxLIS = INT_MIN;
    for(int i = 0  ; i < n ;i++){
        maxLIS = max(maxLIS , lis_at_index[i]);
    }



    delete [] lis_at_index;

    return maxLIS;

}

//dp nlog(n)

int lis_dp2(int n, int arr[]){
    vector<int> vec;//will store our li
    vec.push_back(arr[0]);
    for(int i = 1 ;  i < n ; i++){
        if(vec.at(vec.size()-1) < arr[i]){//appen the num to the lis
            vec.push_back(arr[i]);
        }else{
            //we look for next largets elemnt in this vector and swap our with it to reach the lis optimally
            vector<int>::iterator it = lower_bound(vec.begin() , vec.end() , arr[i]); 
            int index = it - vec.begin();
            vec.at(index) = arr[i];   
        }
    }
    return vec.size();
}
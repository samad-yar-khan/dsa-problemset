#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1#
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	   int dp[1000]={0};// dp[i] store stores the maximum sum increaaisng subseq ending at index i
	   
	   dp[0] = arr[0];
	   
	   int ans = arr[0];
	   for(int i =1;i <n ; i++){
	       int maxSum = -1;
	       for(int j =0;j<i; j++){
	           if(arr[i]>arr[j]){
	               maxSum = max(maxSum ,  dp[j]);
	           }
	       }
	       dp[i] = max(maxSum + arr[i],arr[i]);
            ans = max(ans ,  dp[i]);
	   }
	    
	    return ans;
	    
	}  
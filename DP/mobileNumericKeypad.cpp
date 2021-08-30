#include<bits/stdc++.h>
using namespace std;

///what we need to is that we need to store the 

 long long countMemo(int dialer[4][3],int i , int j , int N , int X[] , int Y[] , long long dp[4][3][26]){
	   
	   //out of bounds
	   if((N>0) && (i>3 || i<0 || j>2 || j <0)){
	       return 0;
	   }
	   //edge case
	   if(i==3 && (j == 0 || j == 2) ){
	       return 0;
	   }         
	   //base case
	   if(N==1){//we can only return the vallue from where we are
	       return 1;
	   }
	   
	   
	   //memoize
	   if(dp[i][j][N] != -1){
	       return dp[i][j][N];
	   }
	   
	   long long ans = 0 ;
	   for(int itr = 0 ; itr < 5 ; itr++){
	       ans = ans + countMemo(dialer , i + X[itr] ,j + Y[itr] , N-1,X ,Y,dp);
	   }
	   
	   dp[i][j][N] =  ans;
	   return ans;

	    
	}
	
	long long getCount(int N)
	{
		// Your code goes here
		
		int dialer[4][3] = {{1,2,3},
		                    {4,5,6},
		                    {7,8,9},
		                    {-1,0,-1}};
	    int X[5] = {0,0,0,-1,1};
	    int Y[5] = {0,1,-1,0,0};
	    long long ans = 0; 
	    
	    long long dp[4][3][26];
	    
	    for(int i = 0 ;i < 4 ; i++){
	        for(int j =0 ; j < 3 ; j++){
	            for(int k = 0 ; k < 26 ; k++){
	                dp[i][j][k] = -1;
	            }
	        }
	    }
	    
	    for(int i =0 ; i < 4 ; i++){
	        for(int j = 0 ; j<3 ;j++){
	            ans = ans + countMemo(dialer ,  i, j , N , X , Y , dp);   
	        }
	    }
	         
		return ans;
	}
#include<bits/stdc++.h>
using namespace std;

//o(n2)
//dp[i][0] stores las endingf at i , ith num is minima
//dp[i][1]--------------------------------------maxima
//we foerm /\/\/\/\/\/\/\/\/\/\/


int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		    int n = nums.size();
		    vector<vector<int>>dp(nums.size(),vector<int>(2,0));
		    dp[0][0]=1;
		    dp[0][1]=1;
		    int ans=1;
		    for(int i =1;i<n ;i++){
		        for(int j = 0;j<i;j++){
		            if(nums[j]>nums[i]){
		                dp[i][1]=max(dp[i][1],dp[j][0]+1);
		                ans = max(ans,dp[i][1]);
		            }else if(nums[j]<nums[i]){
		                dp[i][0]=max(dp[i][0],dp[j][1]+1);
		                ans = max(ans,dp[i][0]);
		            }
		        }
		    }
		    return ans;
		    
		}

    //o(n) solution , here we just have to find the the numbe of maxima and minimas \
    
	int AlternatingaMaxLength2(vector<int>&nums){
		    
		   int n=nums.size();
		   int c =1;
		   if(nums.size()<=2){
		       return n;
		   }
		   int s = nums[1]-nums[0];
		   for(int i =1;i<n-1 ;i++){
		       int s2 = nums[i+1]-nums[i];
		       if(s2==0){
		           continue;
		       }
		       if(s >0 && s2<0 ){
		           c++;
		       }else if(s<0 && s2>0){
		           c++;
		       }
		       s=s2;
		   }
		   c++;
		   return c;
		}



#include<bits/stdc++.h>
using namespace std;

//memo

int helper(int *arr , int n , int* ans){
	  
	    //bc
	    if(n<=0){
	        return 0;
	    }
	    
	    if(ans[n]!=-1){
	        return ans[n];
	    }
	    
	    //ih
	    //take our number
	    int case2 = findMaxSum(arr+2 , n-2) + arr[0];
	    int case1 = findMaxSum(arr+1 , n-1);
	    
	    return max(case1 , case2);
	    
	}
	
	int findMaxSum(int *arr, int n) {
	    // code here
	    int* ans = new int[n+1];
	    for(int i = 0 ; i <= n ; i++){
	        ans[i]= -1;
	    }
	    
	    int Ans = helper(arr , n , ans);
	    delete [] ans ;
	    return Ans;
	  
	}

  //dp with O(1) space beause we need only ans for n-1 and n-2 size of array
int findMaxSum_DP(int *arr, int n) {
	    // code here
	    
	    int a = 0 ;
	    int b = arr[n-1];
        //we can also takke an arry of size n and then instead of a and b we call of ans[n-1]  and ans[n-2]
	    for(int i = 2 ;i <=n ; i++){
	            
	           int C1 =  a + arr[n-i]; //take mine
	           int C2 = b ;
	           
	           int Ans = max(C1 , C2);
	           
	           a = C2;
	           b = Ans;
	        
	    }
	    
	    int Ans = b;
	    return Ans;
	}


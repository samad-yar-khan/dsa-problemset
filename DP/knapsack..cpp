#include<bits/stdc++.h>
using namespace std;

// Code : Knapsack
// Send Feedback
// A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?
// Input Format :
// The first line of the input contains an integer value N, which denotes the total number of items.

// The second line of input contains the N number of weights separated by a single space.

// The third line of input contains the N number of values separated by a single space.

// The fourth line of the input contains an integer value W, which denotes the maximum weight the thief can steal.
// Output Format :
// Print the maximum value of V that the thief can steal.
// Constraints :
// 1 <= N <= 20
// 1<= Wi <= 100
// 1 <= Vi <= 100

// Time Limit: 1 sec
// Sample Input 1 :
// 4
// 1 2 4 5
// 5 4 8 6
// 5
// Sample Output 1 :
// 13
// Sample Input 2 :
// 5
// 12 7 11 8 9
// 24 13 23 15 16
// 26
// Sample Output 2 :
//51






// bruteforce

int knapsack(int wt[], int val[], int n , int W) { 
       // Your code here
    //base case
    //no wts // no linit
    if(n==0 || W==0){
        return 0;
    }
	
 
    //ih
    //take the wt
    int case1 = INT_MIN ;
    int case2 = INT_MIN ;
    
   	if(wt[0]<=W){
        case1 = knapsack( wt+1 , val +1 , n-1 , W-wt[0] ) +  val[0];
    }
    //dont take
     case2 = knapsack( wt+1 , val +1 , n-1 , W);

    return max(case1 , case2);
}

//memo
int knapSack_m(int wt[], int val[], int n,int W, int**arr) 
{ 
       // Your code here
  if(n==0 || W==0){
        return 0;
    }
	//check
    if(arr[W][n] != -1){
        return arr[W][n];
    }
 
    //ih
    //take the wt
    int case1 = INT_MIN ;
    int case2 = INT_MIN ;
    
   	if(wt[0]<=W){
        case1 = knapSack_m( wt+1 , val +1 , n-1 , W-wt[0]  , arr) +  val[0];
    }
    //dont take
     case2 = knapSack_m( wt+1 , val +1 , n-1 , W , arr) ;

    arr[W][n] = max(case1 , case2);

    return arr[W][n];

}

int knapsack(int wt[], int val[], int n , int W) 
    { 
       // Your code her
      int**arr = new int*[W+1];
    for(int i = 0 ; i   <= W ; i++){
        arr[i] = new int[n+1];
        for(int j = 0 ;  j<= n ; j++){
            arr[i][j] =-1;
        }
    }
        int ans = (knapSack_m(wt,val,n,W,arr));
     for(int i = 0 ; i   <= W ; i++){
        delete [] arr[i] ;
    }
    delete [] arr;
        return ans;

    }

//dp
int knapsackDP(int wt[], int val[], int n , int W){ 
    // Your code her
    int**arr = new int*[n+1];
    for(int i = 0 ; i   <= n ; i++){
        arr[i] = new int[W+1];
        for(int j = 0 ;  j<= W ; j++){
            arr[i][j] =0;
        }
    }
    

    for(int i = 0 ; i<=n ;i++){
        arr[i][W] = 0;
    }

    for(int j = 0 ; j<=W ;j++){
        arr[0][j] = 0;
    }

    for(int i = 1 ;  i<=n ; i++){
        for(int j = 1 ; j<= W ; j++){

            int indX = n-i;
            if(wt[indX] > j){ //index is the index of first elemnt if we take an array of size i but from te end
                arr[i][j] = arr[i-1][j];
            }else{
                arr[i][j] = max(arr[i-1][j] , arr[i-1][j-wt[indX]] + val[indX]);
            }
        }
    }

    int ans = arr[n][W];

    for(int i = 0 ; i   <= n ; i++){
        delete [] arr[i] ;
    }
    delete [] arr;
    return ans;

}

/*
Optimal Strategy For A Game 
Medium Accuracy: 52.29% Submissions: 12476 Points: 4
You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

Example 1:

Input:
N = 4
A[] = {5,3,7,10}
Output: 15
Explanation: The user collects maximum
value as 15(10 + 5)
Example 2:

Input:
N = 4
A[] = {8,15,3,7}
Output: 22
Explanation: The user collects maximum
value as 22(7 + 15)
Your Task:
Complete the function maximumAmount() which takes an array arr[] (represent values of N coins) and N as number of coins as a parameter and returns the maximum possible amount of money you can win if you go first.

Expected Time Complexity : O(N*N)
Expected Auxiliary Space: O(N*N)

Constraints:
2 <= N <= 103
1 <= Ai <= 106

Related Courses
*/


#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1#
//brute foorce

//brute force 
/*

backtrack 
the lofic is that we need to play optmamlly , each player whie playing a move claculates in his mind
ho much sum can the other person make ?
if i choose the first elemnt , i call rec on the rest to see how much the other player makes ,
then i backtrack and i see how much the other peerson makes when i select the last elemnt
now i calculate how much i make in bth these cases
how much i make is equal to (total points which cane be made in i to j) - (how much the oother perosn makes)
now i return the max money i can make 


*/
int helper(int * arr , int n , int i , int j , int*sum ){
    
    //bc
    if(i == j){
        return arr[i];
    }

    //ih
    int s = 0;
    if(i == 0){
        s = sum[j];
    }else{
        s = sum[j] - sum[i-1];
    }

    int case1 = helper(arr , n , i+1 , j , sum);
    int case2 = helper(arr , n , i , j-1 , sum);

    int myC1 = s - case1 ;
    int myC2 = s - case2 ;

    return max(myC1 , myC2);

}

long long maximumAmount(int arr[], int n) 
{
   
    int *sum = new int[n+1];
    sum[0] = arr[0];
    
    for(int i = 1 ; i < n ; i++){
        sum[i] = sum[i-1] +  arr[i];
    }

    int ans = helper(arr, n , 0  , n-1 , sum);
    delete [] sum;
    return ans;

}


//memoization
//we can see that atany call we are calllinggg subbarray from (i , j)
//i can at max ragne from i -> (0,n) and j->(0,n) so m at max i can have n2 problems or n2 call
//hence here we use memo


int helper2(int * arr , int n , int i , int j , long long*sum  , long long** dp){
    //bc

    if(i == j){
        return arr[i];
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //ih
    long long s = 0;
    if(i == 0){
        s = sum[j];
    }else{
        s = sum[j] - sum[i-1];
    }

    long long case1 = helper2(arr , n , i+1 , j , sum , dp);
    long long case2 = helper2(arr , n , i , j-1 , sum , dp);

    long long myC1 = s - case1 ;
    long long myC2 = s - case2 ;

    dp[i][j] = max(myC1 , myC2);
    return dp[i][j];


}

long long maximumAmount_memo(int arr[], int n) 
{
   
    long long *sum = new long long[n+1];
    sum[0] = arr[0];
    
    
    long long **dp = new long long *[n+1];
    for(int i = 0 ; i <= n ; i++){
        dp[i] = new long long[n+1];
        for(int j = 0 ;  j<=  n ; j++)
        {
            dp[i][j] = -1;
        }
    }
    
    for(int i = 1 ; i < n ; i++){
        sum[i] = sum[i-1] +  arr[i];
    }

    long  long ans = helper2(arr, n , 0  , n-1 , sum  , dp);
     for(int i = 0 ; i <= n ; i++){
        delete dp[i];
       
    }
    delete [] sum;
    delete [] dp;
    return ans;

}

//dp
//similiar to the beerus and whiz thingg
   long long maximumAmount(int arr[], int n) 
{
   
      long long *sum = new long long[n+1];
    sum[0] = arr[0];
    
    
    long long **dp = new long long *[n+1];
    for(int i = 0 ; i <= n ; i++){
        dp[i] = new long long[n+1];
        for(int j = 0 ;  j<=  n ; j++)
        {
            dp[i][j] = 0;
        }
    }
    
      for(int i = 1 ; i < n ; i++){
        sum[i] = sum[i-1] +  arr[i];
    }
   
    for(int i = n-1 ;  i >=0 ; i--){
        for(int j = i ; j < n ; j++){
            if(i > j){
                continue;
            }else if(i == j){
                dp[i][j] = arr[i];
            }else{
                long long case1 = dp[i+1][j];
                long long case2 = dp[i][j-1];
                long long s = 0;
                    if(i == 0){
                        s = sum[j];
                    }else{
                        s = sum[j] - sum[i-1];
                    }
                dp[i][j]  = max(s-case1 , s-case2);   
            }


        }
    }

    long  long ans = dp[0][n-1];
     for(int i = 0 ; i <= n ; i++){
        delete dp[i];
       
    }
    delete [] sum;
    delete [] dp;
    return ans;

}


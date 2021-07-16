//https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1#
/*
Code : Minimum Count
Send Feedback
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :
The first and the only line of input contains an integer value, 'N'.
 Output format :
Print the minimum count of numbers required.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/

#include<bits/stdc++.h>
using namespace std;



int helper(int n , int* arr){

    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }

    if(arr[n]!=-1){
        return arr[n];
    }

    int ans = INT_MAX;

    for(int i = 1 ; i*i <= n ; i++){
        ans = min(ans , helper(n-(i*i) , arr) + 1);
    } 

    arr[n] = ans;
    return ans;

}

int MinSquares(int n){

    if( n==1 )
    {
        return 1;
    }

    int*arr = new int[n+1];
    for(int i = 0 ; i <=n ; i++){arr[i] = -1 ;}

    int ans = helper(n , arr);


    delete [] arr;
    return ans;
}

int minSquaresDP(int n){

    if( n==1 )
    {
        return 1;
    }

    int*arr = new int[n+1];
    for(int i = 0 ; i <=n ; i++){arr[i] = 0 ;}
    arr[0] = 1 ;
    arr[1] = 1;

    for( int i = 2 ; i <= n ; i++){

        int minAns = INT_MAX;
        for(int j = 1; j*j <= i ; j++){

            minAns = min(minAns , arr[i-j*j] + 1);

        }
        arr[i] = minAns;

    }

    int ans = arr[n];


    delete [] arr;
    return ans;

}

int main(){
    cout<<MinSquares(6);
}
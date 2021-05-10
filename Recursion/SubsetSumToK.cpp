/***

Return subsets sum to K
Send Feedback
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Constraints :
1 <= n <= 20
Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output :
3 3
5 1

You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.


***/

 


#include<iostream>
using namespace std;
int subsetSumToK(int input[], int n, int output[][50], int k){

    //base case
    if(n==0){

        if(k == 0){//found the ans
            output[0][0] = 0 ;
            return 1;
        }else{
            return 0;//no answeers 
        }

    }

    //induction hypothesis
    //we can either have our first elemebt in the subset equal to k or we can have some without it 
    //so we need two output array
    int op1 [10000][50];
    int op2 [10000][50];

    int myElement = input[0];
    int smallOutput1 =  subsetSumToK(input+1 , n-1 , op1 , k);//answers without our elemnts
    int smallOutput2 = subsetSumToK(input +1 , n-1 , op2 , k-myElement); //will return all my subest summing to k which also have firts element

    //induction step

    //now we merge these and first copy the subest summing to k which dont have our element
    for(int i = 0 ; i < smallOutput1 ; i++){
        output[i][0] =  op1[i][0]; //num of columns
        for(int j = 1 ; j <= op1[i][0] ; j ++){
            output[i][j] = op1[i][j];
        }   
    }
    //now before copy subest with our elment we append our lement
      for(int i = 0 ; i < smallOutput2 ; i++){
        output[i + smallOutput1][0] =  op2[i][0] + 1; //num of columns
        output[i + smallOutput1 ][1] = myElement;
        for(int j = 1 ; j <= op2[i][0] ; j ++){
            output[i + smallOutput1][j+1] = op2[i][j];
        }   
    }
    
    return smallOutput1 + smallOutput2;

}
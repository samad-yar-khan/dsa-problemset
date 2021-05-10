/***
 * 
 * Return subset of an array
Send Feedback
Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :

Line 1 : Size of array

Line 2 : Array elements (separated by space)

Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
 * 
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2
***/
#include<iostream>
using namespace std;


int subset(int input[], int n, int output[][20]){

    //bc 
    if(n <= 0){
        output[0][0] = 0 ;
        return 1; //empty set
    }

    //ih
    int smallAnswer = subset(input+ 1 , n-1 , output); //ths should give subste of smaller arrays

    //is

    for(int i = 0 ; i < smallAnswer ; i ++){

        int ourRow =  i+smallAnswer;

        output[ourRow][0] = output[i][0] + 1;//we ll be adding our element to the front
        output[ourRow][1] = input[0] ; ///our elemnt 
        // now we put the rest of the elements of that ith row
        for(int j= 2 ; j <=  output[ourRow][0] ; j++){
            output[ourRow][j] = output[i][j-1];
        }


    }

    return 2*smallAnswer;



}
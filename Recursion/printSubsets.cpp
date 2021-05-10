/*
 Print Subsets of Array
Send Feedback
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 15
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
 */



#include<iostream>
#include<string>
using namespace std;

void printSubset(int input[] , int ipSize , int output [] , int opSize){

    if(ipSize ==  0 ){

        for(int i {0}; i < opSize ; i++){
            cout<<output[i]<<" ";
        }
        cout<<"\n";
        return;

    }

    //is we need to mak a copy of this op array
    int *output2 = new int[opSize + ipSize +1];
    for (int i = 0 ; i < opSize ; i++)
    {
        output2[i] = output[i];///copy now in one output we copy our lement and in the other we dont
    }

    //ih
    output2[opSize] = input[0]; //ek mai daldia ans ek mai nhi dala 
    printSubset( input+1 , ipSize-1 , output  ,  opSize);
    printSubset(input +1 , ipSize -1 , output2 , opSize +1);

    delete [] output2;
    return;

}

void printSubsetsOfArray(int input[], int size) {

    int *output = new int[size+1];

    printSubset(input , size , output , 0);

    delete[] output;

}
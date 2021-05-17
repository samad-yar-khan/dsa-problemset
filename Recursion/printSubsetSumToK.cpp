/*
Print Subset Sum to K
Send Feedback
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1

*/


#include<iostream>
#include<vector>
using namespace std;


//now our output will have a subarray which sums to k
//either our first element will be in thiis subset or it wont


void printSubsetSumToK(int input[], int size, int k , int output[], int sizeOp){

    //base case
    if(size == 0){//no  more elements left
        if(k==0){ ///reached a pt where where k=0 so  op has elemenst equal to k so we print op
            for(int i = 0 ; i < sizeOp ; i++){
                cout<<output[i]<<" ";
            }       
            cout<<"\n";
            return ;
        }else{//if array is exhausted but k isnt 0 , we just return , not a subarray which eqquals  k
            return;
        }
    }
    //induction step
    //we either have our elemnt in the subarray or we dont
    int ourElement = input[0];

    // we need to duplicate the array 
    int* duplicateOutput = new int[sizeOp + size + 1];
    
    for(int i = 0 ; i < sizeOp ; i++){
        duplicateOutput[i]=output[i];
    }   

    //put our elemnt at the end of duplicate
    duplicateOutput[sizeOp] = input[0]; //case 2

    //is
    printSubsetSumToK(input + 1 , size-1 , k , output , sizeOp);
    
    printSubsetSumToK(input + 1 , size-1 , k  - ourElement , duplicateOutput , sizeOp+1);





    delete [] duplicateOutput;

}

void printSubsetSumToK(int input[], int size, int k){
    int *output = new int[size];

    printSubsetSumToK(input , size , k , output , 0);

    delete[] output;
}

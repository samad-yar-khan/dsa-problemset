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

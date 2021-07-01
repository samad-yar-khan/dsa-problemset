#include <iostream>
using namespace std;

void permute(char* input , int index){

    //bc
    if(input[index] == '\0'){
        cout<<input<<"\n";
        return;
    }

    for(int i=  index ; input[index]!='\0' ; i++){
        //swap elemnts with first index
        swap(input[index] , input[i]);
        //move the pointer again and do ih
        permute(input , index +1);
        //backtrack ans reset the original array
        swap(input[index] , input[i]);
    }
}
#include <iostream>
#include <string>
#include <set>
using namespace std;

//find all permutation of a string using backkstarickking
//now if a string has non unqiue chars we must use a set , and srore only unqqiue values

void permute(char* input , int index , set<string> & permutationsSet){

    //bc
    if(input[index] == '\0'){
        string myString (input);
        permutationsSet.insert(myString);
        return;
    }

    for(int i=  index ; input[i]!='\0' ; i++){
        //swap elemnts with first index
        swap(input[index] , input[i]);
        //move the pointer again and do ih
        permute(input , index +1 , permutationsSet);
        //backtrack ans reset the original array
        swap(input[index] , input[i]);
    }
}

int main(){
    

    char str[100];
    cin>>str;

    set<string> ans;

    permute(str , 0 , ans);

    for(auto a : ans  ){
        cout<<a<<"\n";
    }


    return 0;
}
#include<iostream>
#include<string>
using namespace std;


int returnPermutations(string input, string output[]){

    //bc 
    if(input.length() == 0 ){
        output[0] = "";
        return 1 ; //null permutaun
    }
    
    //ih
    //weget substring for smaller values
    string smallOutput[10000];
    int smallOutputSize = returnPermutations(input.substr(1) , smallOutput);

    //now we have got permutation of smaller sstring and we nee dto put our cahracter at every positiion
    //induction step

    int outputIndex{0};

    for(int i = 0 ; i < smallOutputSize ; i++){

        string smallPerm = smallOutput[i];

        for(int j = 0 ; j <= smallPerm.length() ; j++){

            output[outputIndex] = smallPerm.substr(0,j) + input[0] + smallPerm.substr(j);
            outputIndex++;
        }

    }

    return outputIndex;

}

int main(){
    string hey{"hey"};

    string op[10000];
    int x = returnPermutations(hey , op);
    for(int i = 0 ; i < x; i++){
        cout<<op[i]<<"\n";
    }
}
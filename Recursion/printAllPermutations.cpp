#include<iostream>
#include<string>
using namespace std;

void printPermutations(string input , string output){

    if(input.length() == 0){
        cout<<output<<"\n";
        return;
    }

    for(int i = 0 ; i<= output.length() ; i++){

        printPermutations(input.substr(1) , output.substr(0,i) + input.at(0) + output.substr(i));

    }

}

void printPermutations(string input){

    string output{""};
    printPermutations(input , output);

}

int main(){

    return 0;
}
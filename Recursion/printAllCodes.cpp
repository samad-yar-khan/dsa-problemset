#include<iostream>
#include<string>
using namespace std;


void printAllPossibleCodes(string input , string output) {

    //bc
    if(input.length() == 0){
        cout<<output<<"\n";
        return;
    }

    //is

    char a = 'a';
    int firstDigit = input[0]-'0';
    int secondDigit = 0;
    int secondNumber = 0 ;
    if(input.length() > 1){
        secondDigit = input[1] - '0';
        secondNumber = 10*firstDigit + secondDigit;    
    }

    //now we see append our char at the start
    char ourString1 = a + firstDigit  - 1;

    //induction hypothesu
    printAllPossibleCodes(input.substr(1) , output + ourString1 );
     
    if( input.length() > 1 && secondNumber < 27){
        
        char ourString2 = a + secondNumber - 1 ;
        printAllPossibleCodes(input.substr(2) , output + ourString2);

    }




}

void printAllPossibleCodes(string input) {

    string output{""};

    printAllPossibleCodes(input , output);

}


int main(){

    string inp{""};
    cin>>inp;

    printAllPossibleCodes(inp);

}



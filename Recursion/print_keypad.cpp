#include<iostream>
using namespace std;
#include<vector>
#include<string>

void printKeypadAns(int n , string keys[] , string output){

    //bc
    if(n<=1){
        //just print the op as noting to add
        cout<<output<<"\n";
        return;
    }
    //is
    // we just need to append our digits output at the start of our output and rest willl be done by our function
    
    int my_digit = n%10;
    int small_n = n/10;

    for(int i = 0 ; i < keys[my_digit].length() ; i++){

        printKeypadAns(small_n , keys , keys[my_digit].at(i) + output);

    }

}


void printKeypad(int n){

    //we need a keys arra
    string keys[] = {"" , "" , "abc" , "def","hgi" , "jkl" , "mno" , "pqrs" , "uvw" , "xyz"};
    string output{""};
    printKeypadAns(n , keys , output);
}

int main(){

    int n{0};
    cin>>n;
    printKeypad(n);

}
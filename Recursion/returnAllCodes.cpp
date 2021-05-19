/*

Return all codes - String
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw

*/


#include<iostream>
using namespace std;

int getCodes(string input, string output[10000]) {

    //bc
    if(input.length() == 0){
        //ek hi answer hos akte hai nulll
        output[0] = "";
        return 1;
    }

    //induction hypothesis

    int firstNum = input[0] - '0';

    //so now we need to call rec on smaler string
    int smallOutput1 = getCodes(input.substr(1) , output);//if 112 is our string , this gives ans for 12 and we append 1s code in this
    
    int smallOutput2=0;
    string output2[10000]; 
    int secondNum = 0 ;//secon digit 
    if(input.length() > 1){
        secondNum = (10*firstNum) + (input[1] - '0');
    }

    if(input.length() > 1 && secondNum<27){

        smallOutput2= getCodes(input.substr(2) , output2);//2 for 11

    }
    
    //induction step

    // now we first need to appedn our first number scode  to the output strig from case1
    char a='a';

    for(int i = 0 ; i < smallOutput1 ; i++){
        char ourChar = a+ firstNum-1;
        output[i] = ourChar + output[i];
    }

    for(int i = 0 ; i < smallOutput2 ; i++){
        char ourChar = a+secondNum-1;
        output[i+smallOutput1] = ourChar+ output2[i];

    }

    return smallOutput1 + smallOutput2;
}


int main(){

    string inp{""};
    cin>>inp;

    string output[10000];

    int op = getCodes(inp , output);

    for(int i = 0 ; i < op ; i++){
        cout<<output[i]<<"\n";
    }

}



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

    //base case
    if(input.length() == 0){//for empty string ans would be empy string
        output[0] = "";
        return 1;
    }

    //ih 
    //we need to find first num and first two nums
    int firstDigit = input.at(0) - '0';
    int secondDigit = 0;

    if(input.length()>1){
        int secondDigit = input.at(1) - '0';    
    }

    int tempNumber = (secondDigit*10) + firstDigit;
    //we get codes with substring of length n-1
    int codesOp1 = getCodes(input.substr(1) , output);

    if(tempNumber<=26)




    delete [] output;

}





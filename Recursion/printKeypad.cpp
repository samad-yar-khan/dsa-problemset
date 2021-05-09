#include<iostream>
#include<string>
using namespace std;

/*
Print Keypad Combinations Code
Send Feedback
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

void printKeypad(int n , string output , string keys[]){

    if(n <= 1){

        cout<<output<<"\n";
        return;

    }

    //else i key my keys in first and do rec

    int myNum = n%10;
    int restNum = n/10;
    string myKeys = keys[myNum];


    for(int i{0} ; i < myKeys.length() ; i++){

        printKeypad(restNum , myKeys.at(i) + output , keys);

    }




}


void printKeypad(int n){

    string key [] = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz" };
    string output = "";
    printKeypad(n , output , key);

}

int main(){

    int n{0};
    cin>>n;

    printKeypad(n);

}

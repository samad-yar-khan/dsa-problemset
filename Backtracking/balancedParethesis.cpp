#include<iostream>
#include<string>
#include<vector>
using namespace std;

//https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1

void helper(int leftBrackets , int rightBrackets , string &s  , vector<string>&vec ,int n , int index ){

    //base case
    if(leftBrackets==0 && rightBrackets==0 && index == 2*n ){
        vec.push_back(s);    
        return;
    }

    //edge case
    if(rightBrackets < leftBrackets){
        return;
    }

    //ih
    if(leftBrackets > 0){
        s.at(index) = '(';
        helper(leftBrackets -1 , rightBrackets , s , vec , n , index+1);
    }

    if(rightBrackets > leftBrackets){
        s.at(index) = ')';
        helper(leftBrackets  , rightBrackets -1 , s , vec , n , index+1);
    }

    s.at(index) = '\0';


}

vector<string> AllParenthesis(int n) 
{
        // Your code goes here 
        vector<string> ans;
        string s(2*n +1 , '\0');
        helper(n , n , s ,ans , n , 0);
        return ans;
}
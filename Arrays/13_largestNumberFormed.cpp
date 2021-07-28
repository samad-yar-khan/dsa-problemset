//https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1#
/*
Largest Number formed from an Array 
Medium Accuracy: 50.0% Submissions: 16402 Points: 4
Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.The result is going to be very large, hence return the result in the form of a string.

Example 1:

Input: 
N = 5
Arr[] = {3, 30, 34, 5, 9}
Output: 9534330
Explanation: Given numbers are {3, 30, 34,
5, 9}, the arrangement 9534330 gives the
largest value.
Example 2:

Input: 
N = 4
Arr[] = {54, 546, 548, 60}
Output: 6054854654
Explanation: Given numbers are {54, 546,
548, 60}, the arrangement 6054854654 
gives the largest value.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function printLargest() which takes the array of strings arr[] as parameter and returns a string denoting the answer.
*/

#include<bits/stdc++.h>
using namespace std;



bool com(string a,string b){
	 return a+b>b+a;
}

	string printLargest(vector<string> arr) {
	    // code here
	    sort(arr.begin() , arr.end(), com);
	    string str {""};
	    for(int i = 0  ; i < arr.size() ; i++) {
	 	    str+= arr[i];
	    }
	   
	   return str;
	}
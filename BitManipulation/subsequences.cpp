/**
Power Set 
Easy Accuracy: 37.15% Submissions: 7345 Points: 2
Given a string S find all possible substrings of the string in lexicographically-sorted order.

Example 1:

Input : str = "abc"
Output: a ab abc ac b bc câ€‹
Explanation : There are 7 substrings that 
can be formed from abc.
Example 2:

Input: str = "aa"
Output: a a aa
Explanation : There are 3 substrings that 
can be formed from aa.
Your Task:
You don't need to read ot print anything. Your task is to complete the function AllPossibleStrings() which takes S as input parameter and returns a list of all possible substrings(non-empty) that can be formed from S in lexicographically-sorted order.
 

Expected Time Complexity: O(2n) where n is the length of the string
Expected Space Complexity : O(n * 2n)
 

Constraints: 
1 <= Length of string <= 16 
https://practice.geeksforgeeks.org/problems/power-set4302/1#
*/


#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>



	    void insertSubset(string s , vector<string> &vec , int n){
	               
	           //n will be a number , which when conver
	           string output ="";
	           int stringPointer = 0 ;
	           while(n > 0){
	               int setBit = n&1;
	               if(setBit){
	                    
	                    output = output + s.at(stringPointer);
	                   
	               }
	               
	               stringPointer++;
	               n = n >> 1;
	           }
	            vec.push_back(output);
	        
	    }
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> vec;
		    for(int i = 1 ; i < (1<<s.length()) ; i++ )
		    {
		        insertSubset(s,vec , i);
		    }
		    
		    sort(vec.begin() , vec.end());
		    return vec;
		    
		}
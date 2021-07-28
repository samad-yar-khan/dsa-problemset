#include<bits/stdc++.h>
using namespace std;

/*
Longest Common Subsequence 
Medium Accuracy: 49.98% Submissions: 40247 Points: 4
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.
Example 2:

Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is
"AC" of length 2.
Your Task:
Complete the function lcs() which takes the length of two strings respectively and two strings as input parameters and returns the length of the longest subsequence present in both of them.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
1<=size(str1),size(str2)<=103
*/

//brute force
 int helper(int x , int y , int i , int j , string& s1 , string& s2 ){
        
        //base case one of the sstring is  null
        if(i >= x || j >=y){
            return 0;
        }
        
        //if first two letters are same
        if(s1.at(i) == s2.at(j)){
            return 1 + helper(x , y , i+1 , j+1 , s1 , s2);
        }
        
        //if first two chars are not same
        int case1 = helper(x,y,i+1,j,s1,s2);//shorter a 
        int case2 = helper(x,y,i,j+1,s1,s2);//shorter b
        
        return max(case1  , case2);
        
    
    }
    
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        return helper(x,y,0,0,s1,s2);    
    }

    //memoizatio
        
    int helper_memo(int x , int y , int i , int j , string& s1 , string& s2  , vector<vector<int>>& vec){
        
        //base case one of the sstring is  null
        if(i >= x || j >=y){
            return 0;
        }
        
        //check memo
        if(vec[i][j] != -1){
            return vec[i][j];
        }
        
        //if first two letters are same
        
        if(s1.at(i) == s2.at(j)){
            vec[i][j]= 1 + helper_memo(x , y , i+1 , j+1 , s1 , s2 , vec);
            return vec[i][j];
        }
        
        //if first two chars are not same
        int case1 = helper_memo(x,y,i+1,j,s1,s2 , vec);//shorter a 
        int case2 = helper_memo(x,y,i,j+1,s1,s2 ,vec);//shorter b
        
        vec[i][j] = max(case1  , case2); 
        return vec[i][j];
        
    
    }
    
    int lcs_memo(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> memo(1001 , vector<int>(1001 , -1)) ;
        int ans = helper_memo(x,y,0,0,s1,s2 , memo);    
        return ans;
    }

    //dp
    int lcsDP(int x, int y, string s1, string s2){

          vector<vector<int>> vec(1001 , vector<int>(1001,0)) ;

      
        
        for(int i = x-1 ; i >= 0 ; i--){
            for(int j = y-1 ; j >= 0 ; j--){
                    
                if(s1.at(i) == s2.at(j)){
                    vec[i][j] = 1+ vec[i+1][j+1];
                }else{
                    int c1 = vec[i+1][j+1];
                    int c2 = vec[i+1][j];
                    int c3 = vec[i][j+1];
                    vec[i][j] = max(c1 , max(c2,c3));
                }
                
            }
        }
        

        int ans = vec[0][0];
        return ans;


    }
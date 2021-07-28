/*
https://practice.geeksforgeeks.org/problems/edit-distance3702/1

Code : Edit Distance
Send Feedback
Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note
Strings don't contain spaces
Input Format :
The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.
Output Format :
The first and only line of output contains the edit distance value between the given strings.
Constraints :
1<= m,n <= 10
Time Limit: 1 second
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/


#include<bits/stdc++.h>
using namespace std;


/*

int editDistance(string S, string T){

  

	//write your code here

    //base  case
    if(S.length() == 0 || T.length() == 0){
        return max(S.length() , T.length());
    }
    

    
    int ans = 0;
    //ih
    if(S.at(0) == T.at(0)){
        ans = editDistance(S.substr(1) , T.substr(1));
    }
    else{
        //add my S's first char at the start  of T
        int c1 =  editDistance(S.substr(1) , T);
        
        //replace first char of T to S's
        int c2 =  editDistance(S.substr(1) , T.substr(1));
        
        //delete first char of T
        int c3 = editDistance(S , T.substr(1));
        
        ans = 1 + min(c1,min(c2,c3));
        
    }
    
    return ans;
    
}

*/


int editDistance(string s1, string s2) {

    ///base case
    if(s1.length() == 0 || s2.length () == 0){
        return max(s1.length() , s2.length());
    }

    //is

    if(s1.at(0) == s2.at(0)){
        return 1+editDistance(s1.substr(1) , s2.substr(1));
    }

    //ih
    int case1 =INT_MAX;
    int case2 =INT_MAX;
    int case3 =INT_MAX;

    //delete  in 1
    case1 = editDistance(s1.substr(1) , s2);
    //swap
    case2 = editDistance(s1.substr(1),s2.substr(1));
    //add cahar there
    case3 = editDistance(s1,s2.substr(1));

    return min(case1,min(case1,case3));

}

int memo_helper(string s1, string s2 , int**memo){
    
    if(s1.length() ==0 ||s2.length() ==  0){
        return max(s1.length() , s2.length());
    }

    //memoizqation
    if(memo[s1.length()][s2.length()] != -1){
        return memo[s1.length()][s2.length()];//length from end
    }

    //ih
    //no change if first chars  are same 
    if(s1.at(0)== s2.at(0)){
        return memo_helper(s1.substr(1) , s2.substr(1) , memo);
    }

      //ih
    int case1 =INT_MAX;
    int case2 =INT_MAX;
    int case3 =INT_MAX;

    //delete  in 1
    case1 = memo_helper(s1.substr(1) , s2 , memo);
    //swap
    case2 = memo_helper(s1.substr(1),s2.substr(1) , memo);
    //add cahar there
    case3 = memo_helper(s1,s2.substr(1) , memo);

    memo[s1.length()][s2.length()] = 1 + min(case1 , min(case2 , case3));
    return memo[s1.length()][s2.length()];

}
//
int editDistance_memo(string s1, string s2) {

    int**arr = new int*[s1.length()+1];
    for(int i = 0 ; i   <= s1.length() ; i++){
        arr[i] = new int[s2.length()+1];
        for(int j = 0 ;  j<= s2.length() ; j++){
            arr[i][j] =-1;
        }
    }

    int ans = memo_helper(s1 , s2 , arr);

    for(int i = 0 ; i   <= s1.length() ; i++){
        delete [] arr[i] ;
    }
    delete [] arr;
    return ans;

}

//dp
int editDistance_dp(string s1, string s2) {

    int**arr = new int*[s1.length()+1];
    for(int i = 0 ; i   <= s1.length() ; i++){
        arr[i] = new int[s2.length()+1];
        for(int j = 0 ;  j<= s2.length() ; j++){
            arr[i][j] =-1;
        }
    }

    int x = s1.length();
    int y = s2.length();

    //base cases
    //first row , s1 empty
    for(int j = 0; j <= y ; j++){
        arr[0][j] = j;
    }
    //first col empty , s2 empty 
    for(int i=0; i<= x ; i++){
        arr[i][0] = i;
    }

    for(int i = 1 ; i <= x ; i++){
        for(int j = 1 ; j <= y ; j++){
            
            int indexS1 = x-i;
            int indexS2 = y-j;

            if(s1.at(indexS1) == s2.at(indexS2)){
                arr[i][j] = arr[i-1][j-1];
            }else{
                //swap firt char
                int case1 = arr[i-1][j-1];
                //delete first char of s2
                int case2 = arr[i-1][j];
                //add char in s
                int case3 = arr[i][j-1];

                arr[i][j]=min(case1 , min(case2 , case3)) +1;                

            }
        }
    }
    int ans = arr[x][y];



    for(int i = 0 ; i   <= s1.length() ; i++){
        delete [] arr[i] ;
    }
    delete [] arr;
    return ans;

}
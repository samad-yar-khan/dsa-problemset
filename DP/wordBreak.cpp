#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/word-break1352/1#

 int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_map<string , int> dict;
        
        //hashmap
        
        for(int i =0 ;i < B.size() ; i++){
            dict.insert({B[i] , 1});
        } 
        vector<int> numWords(A.length(),0);
        
        for(int end=0;end<=A.length()-1;end++){
            int currCount = 0;
            for(int start =0;start<=end ; start++){
                if(dict.count(A.substr(start,end-start+1))==1){
                   if(start-1<0){
                       currCount++;
                   }else{
                       currCount += numWords[start-1];
                   }
                }
            }
            numWords[end]=currCount;
        }
        // return helper(A , dict , 0 , A.length()-1, dp);
        if(numWords[A.length()-1] >0){
            return 1;
        }
        return 0;
        
    }

    //we arre gonnna stor ethe numbeof words which we can form with all the prefixed 
    //for eavh inmdex we see the words we can dform using the suffixs and add the prefic value
    
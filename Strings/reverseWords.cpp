#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/reverse-words-in-a-string/

 string reverseWords(string s) {
        
        int i = s.length() -1 ;
        string ans="";
        while(i>=0){
            int j = i;
            while(j>=0 && s[j] == ' '){
                j--;
            }
            i=j;
            while(j>=0 && s[j] != ' '){
                j--;
            }
            int si = j+1;
            int ei = i;
            if(ei-si+1>0){
                ans+=s.substr(si,ei-si+1);
            }
            while(j>=0 && s[j] == ' '){
                j--;
            }
            if(j>=0){
                ans+=" ";
            }
            i=j;
        }
        return ans;
        
    }
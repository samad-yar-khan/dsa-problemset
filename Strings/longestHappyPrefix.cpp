#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-happy-prefix/

/*
CONSIDER abcabcba
lps will store longtres prefix suffix
str = a b c a b c b a
lps = 0 0 0 1 2 3 0 0 
*/

    string longestPrefix(string s) {
        vector<int>lps(s.length(),0);
        int i =0;
        int j =1;
        int ans =0;
        while(i<s.length() && j <s.length()){
            if(s[i]==s[j]){
                lps[j]=i+1;
                j++;
                i++;
            }else if(s[i]!=s[j] && i==0){
                j++;
            }else{
                i = lps[i-1];
            }
        }
        return s.substr(0,lps[s.length()-1]);
    }
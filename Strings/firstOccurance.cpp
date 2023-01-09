#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

//kmp algp
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        string&s = needle;
        string&h = haystack;
        vector<int>lps(m,0);
        lps[0] = 0;
        int i = 0;
        int j = 1;
        while(i<m && j <m){
            if(s[i] == s[j]){
                lps[j] = i+1;
                i++;
                j++;
            }else if(s[i]!=s[j] && i>0){
                i=lps[i-1];
            }else{
                j++;
            }
        }
        i=0;j=0;int st=0;
        while(i<n && j<m){
            if(h[i] == s[j]){
                i++;j++;
            }else if(h[i] != s[j] && j>0){
                j=lps[j-1];
            }else{
                i++;
            }
        }
        if(j<m){
            return -1;
        }
        return i-m;
    }
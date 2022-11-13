#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/removing-stars-from-a-string/

    string removeStars(string s) {
        stack<char>ch;
        for(int i =0;i<s.length();i++){
            if(s[i] == '*'){
                if(ch.size()){
                    ch.pop();
                }
            }else{
                ch.push(s[i]);
            }
        }
        string ans="";
        while(ch.size()){
            ans+=ch.top();
            ch.pop();
        }
        int i = 0;
        int j = ans.length()-1;
        while(i<j){
            swap(ans[i],ans[j]);
            i++;j--;
        }
        return ans;
    }
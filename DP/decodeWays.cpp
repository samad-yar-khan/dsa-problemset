#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/decode-ways/
int numDecodings(string s) {
        vector<int>ans(s.length()+1,0);
        if(s[s.length()-1]-'1' +1>0){
            ans[s.length() - 1]=1; 
        }
        
        
        ans[s.length()]=1; 
        for(int i =s.length() -2 ; i>=0 ;i--){
            int curr = s[i]-'1'+1;
            int n = s[i+1] - '1' + 1;
            int a=0;
            if(s[i] == '0'){
                continue;
            }
            if(curr >=0 &10*curr + n <=26){
                a+=ans[i+2];
            } 
            a+=ans[i+1];
            ans[i] = a;
        }
        return ans[0];
    }
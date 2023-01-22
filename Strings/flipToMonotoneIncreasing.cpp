#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/flip-string-to-monotone-increasing/

int minFlipsMonoIncr(string s) {
        int n = s.length();
        int cs =0;
        for(int i =0;i<n;i++){
            cs+=s[i]-'0';
        }
        int ans = min(n - cs,cs);
        int CS= s[0]-'0';
        for(int i =1;i<n;i++){
            int left = CS;
            int right =cs-CS;
            ans = min(ans,left+n-i-right);
            CS += s[i]-'0';
        }
       return ans;
    }
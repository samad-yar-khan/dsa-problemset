#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/submissions/


    int longestPalindrome(vector<string>& words) {
        vector<vector<int>>mp(26, vector<int>(26,0));
        for(int i =0;i<words.size();i++){
            int a = words[i][0]-'a';
            int b = words[i][1]-'a';
            mp[a][b] += 1;
        }

        int ans =0;
        bool mid = false;
        for(int i = 0;i<26;i++){
            for(int j =0;j<26;j++){
                if(i==j){
                    ans+=((mp[i][j]/2)*4);
                    mid = (mp[i][j]%2) || mid;
                }else{
                    ans+=((min(mp[i][j],mp[j][i]))*4);
                    mp[i][j] = 0;
                }
            }
        }
        if(mid){
            ans+=2;
        }
        return ans;
    }
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimum-window-substring/
    bool check(unordered_map<char,int>&tm,unordered_map<char,int>&sm){
        for(auto i =tm.begin();i!=tm.end();i++){
            // cout<<" "<<sm[i->first]<<"--"<<i->second<<" ";
            if(sm[i->first] < i->second){
                return false;
            }
        }
        // cout<<"\n";
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int>tm;
        if(s.length() ==0 || t.length() == 0){
            string ans("");
            return ans;
        }
        for(int i =0;i<t.length();i++){
            tm[t[i]]++;
        }
        unordered_map<char,int>sm;
        int i =0;
        int j =0;
        int ai=0;
        int bi=0;
        int ans =INT_MAX;
        while(j<s.length()){
            if(check(tm,sm)){
                if(j-i < ans){
                    ans = j-i+1;
                    ai=i;
                    bi=j;
                }
                // cout<<ans<<"\n";
                sm[s[i]]--;
                // cout<<i<<","<<j<<"\n";
                i++;
                
            }else{
                // cout<<i<<"-"<<j<<"\n";
                sm[s[j]]++;
                // cout<<s[j]<<"-"<<sm[s[j]]<<"\n";
                j++;
            }
        }
        while(i<s.length()){
            if(check(tm,sm)){
                if(j-i+1 < ans){
                    ans = j-i+1;
                    ai=i;
                    bi=j;
                }
                sm[s[i]]--;
            }
                i++;
        }
        if(ans == INT_MAX){
            string ansf("");
            return ansf;
        }
        string ansf = s.substr(ai,bi-ai);
        return ansf;
    }
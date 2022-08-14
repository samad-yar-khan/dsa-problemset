#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/substring-with-concatenation-of-all-words/
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>word_map;
        for(int i =0;i<words.size();i++){
            if(word_map.count(words[i])){
                word_map[words[i]]+=1;   
            }else{
                word_map[words[i]]=1;
            }
        }
        vector<int> ans;
        int len = words[0].length();
        for(int k = 0; k<len;k++){
            int i = k;
            unordered_map<string,int>mp(word_map);
            int j =i;
            while(i+(words.size()*len)<=s.length() && j+len<=s.length()){
                string curr = s.substr(j,len);
                if(word_map.count(curr)==0){
                    mp=word_map;
                    j+=len;
                    i=j;
                }else if(mp.count(curr) == 0){
                    mp[s.substr(i,len)]++;
                    i+=len;
                    j=max(i,j);
                }else{
                    mp[curr]--;
                    if(mp.count(curr) && mp[curr] ==0){
                        mp.erase(curr);   
                    }
                    if(mp.empty()){
                        mp[s.substr(i,len)]++;
                        ans.push_back(i);
                        i+=len;
                        j+=len;
                    }else{
                        j+=len;
                    }
                }
            }   
        }
        return ans;
    }
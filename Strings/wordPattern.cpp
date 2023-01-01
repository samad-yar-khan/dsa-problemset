#include<bits/stdc++.h>
using namespace std;
    bool wordPattern(string pattern, string s) {
        vector<string>pt(26,"");
        unordered_map<string,int>kt;
        int i =0;
        int k =0;
        while(i<s.length() && k<pattern.length()){
            if(s[i] == ' '){
                i++;continue;
            }
            int j = i;
            while(j<s.length() && s[j]!=' '){
                j++;
            }
            string st = s.substr(i,j-i);
            if(pt[pattern[k]-'a']=="" && kt.count(st) == 0){
                
                pt[pattern[k]-'a'] = st;
                kt[st] = pattern[k]-'a';
            }else if(pt[pattern[k]-'a'] != st || kt[st]!=pattern[k]-'a'){
             
              
                return false;
            }
            i=j;
            k++;
        }
        if (i<s.length() || k<pattern.length()){
            return false;
        }
        return true;
    }
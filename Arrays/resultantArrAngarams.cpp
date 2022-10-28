#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/

    vector<string> removeAnagrams(vector<string>& w) {
        int i =0;
        vector<int>f(26,0);
        for(int i =0;i<w[0].length();i++){
            f[w[0][i]-'a']++;
        }
        int j =1;
        vector<string>ans;
        int n = w.size();
        while(i<n && j<n){
            vector<int>cf(26,0);
            for(int k =0;k<w[j].length();k++){
                cf[w[j][k]-'a']++;
            }
            bool match = true;
            for(int k =0;k<26;k++){
                if(f[k] != cf[k]){
                    match = false;
                    break;
                }
            }
            if(match){
                j++;
            }else{
                ans.push_back(w[i]);
                i=j;
                f=cf;
                j++;
            }
        }
        if(i<n){
            ans.push_back(w[i]);
        }
        return ans;
    }
#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/optimal-partition-of-string/

    int partitionString(string s) {
        vector<int>f(26,0);
        int c=0;
        for(int i =0;i<s.length();i++){
            int ind=s[i]-'a';
            if(f[ind]==1){
                c++;
                for(int j =0;j<26;j++){
                    f[j] =0;
                }
                f[ind] =1;
            }else{
                f[ind]++;
            }
        }
        c++;
        return c;
    }
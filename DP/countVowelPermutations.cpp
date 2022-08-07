#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-vowels-permutation/
long long modVal = 1000000007;
//memoize
    long long solve(int n , char p, vector<char>& chars,vector<vector<long long int>>&dp){
        if(n==0){
            return 1;
        }
        long long ans =0;
        if(p == '\0'){
            for(int i =0;i<5;i++){
                long long ta = solve(n-1,chars[i],chars,dp);
                ta%=(modVal);
                ans+=ta;
                ans%=modVal;
            }
        }
        int charsInd=0;
        for(int i =0;i<chars.size();i++){
            if(p == chars[i]){
                charsInd = i;
                break;
            }
        }
        if(dp[n][charsInd]!=-1){
            return dp[n][charsInd];
        }
        if(p == 'a'){
            long long ta = solve(n-1,'e',chars,dp);
            ta%=(modVal);
            ans+=ta;
            ans%=modVal;
        }
        if(p == 'e'){
            long long ta = solve(n-1,'a',chars,dp);
            long long ta2 = solve(n-1,'i',chars,dp);
            ta%=(modVal);
            ans+=ta;
            ans%=modVal;
            ta2%=modVal;
            ans+=ta2;
            ans%=modVal;
        }
        if(p == 'i' ){
            for(int i =0;i<5;i++){
                if(chars[i] != 'i'){
                    long long ta = solve(n-1,chars[i],chars,dp);
                    ta%=(modVal);
                    ans+=ta;
                    ans%=modVal;
                }
            }
        }
        if(p == 'o'){
            long long ta = solve(n-1,'i',chars,dp);
            long long ta2 = solve(n-1,'u',chars,dp);
            ta%=(modVal);
            ans+=ta;
            ans%=modVal;
            ta2%=modVal;
            ans+=ta2;
            ans%=modVal;
        }
        if( p == 'u'){
            long long ta = solve(n-1,'a',chars,dp);
            ta%=(modVal);
            ans+=ta;
            ans%=modVal;
        }
        dp[n][charsInd] = ans;
        return ans;
    }

    
    int countVowelPermutation(int n) {
        vector<char> vec;
        vec.push_back('a');
        vec.push_back('e');
        vec.push_back('i');
        vec.push_back('o');
        vec.push_back('u');
        vector<vector<long long int>>dp(n+1,vector<long long int>(5,0));
        unordered_map<char,int>maps;
        maps['a'] = 0;
        maps['e'] = 1;
        maps['i'] = 2;
        maps['o'] = 3;
        maps['u'] = 4;
       
        for(auto i = maps.begin() ; i != maps.end() ; i++){
            dp[0][i->second] = 1;
        }
        for(int N = 1;N<=n;N++){
            for(auto j = maps.begin() ; j != maps.end() ; j++){
                long long ans=0;
                int ind = j->second;
                if(j->first == 'a'){
                    long long ta = dp[N-1][maps['e']];
                    ta%=(modVal);
                    ans+=ta;
                    ans%=modVal;
                }
                if(j->first == 'e'){
                    long long ta = dp[N-1][maps['a']];
                    long long ta2 = dp[N-1][maps['i']];
                    ta%=(modVal);
                    ans+=ta;
                    ans%=modVal;
                    ta2%=modVal;
                    ans+=ta2;
                    ans%=modVal;
                }
                if(j->first == 'i' ){
                    for(int i =0;i<5;i++){
                        if(vec[i] != 'i'){
                            long long ta = dp[N-1][maps[vec[i]]];
                            ta%=(modVal);
                            ans+=ta;
                            ans%=modVal;
                        }
                    }
                }
                if(j->first == 'o'){
                    long long ta = dp[N-1][maps['i']];
                    long long ta2 = dp[N-1][maps['u']];
                    ta%=(modVal);
                    ans+=ta;
                    ans%=modVal;
                    ta2%=modVal;
                    ans+=ta2;
                    ans%=modVal;
                }
                if( j->first == 'u'){
                    long long ta = dp[N-1][maps['a']];
                    ta%=(modVal);
                    ans+=ta;
                    ans%=modVal;
                }
                dp[N][ind] = ans;
            }
        }
        // long long ans = solve(n,'\0',vec,dp);
        long long ans =0;
        for(int i=0;i<5;i++){
            long long ta=dp[n-1][i];
            ta%=modVal;
            ans+=ta;
            ans%=modVal;
        }
        ans = ans%(modVal);
        return ans;
        // long long ans = solve(n,'\0',vec,dp);//memoization 
        return ans;
    }
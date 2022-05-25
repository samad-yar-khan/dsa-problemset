#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/russian-doll-envelopes/
static bool comp(pair<int,int>&p1, pair<int,int>&p2){
        if(p1.first==p2.first){
            return p1.second>p2.second;
        }
        return p1.first < p2.first;
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<pair<int,int>>p;
        int n = envelopes.size();
        for(int i =0;i<n;i++){
            p.push_back(make_pair(envelopes[i][0],envelopes[i][1]));
            
        }
        sort(p.begin(),p.end(),comp);
        
        
            vector<int>lis_a;
        for(int i =0;i<n;i++){
            lis_a.push_back(p[i].second);
        }
            
            vector<int>dp;
            dp.push_back(lis_a[0]);
            for(int i =1;i<n;i++){
                if(lis_a[i] > dp[dp.size()-1]){
                    dp.push_back(lis_a[i]);
                }else{
                    int ind = lower_bound(dp.begin(),dp.end(),lis_a[i])-dp.begin();
                    dp[ind] = lis_a[i];
                }
            }
        for(auto i :p){
            cout<<i.first<<" ";
        }
        return dp.size();
        }
        
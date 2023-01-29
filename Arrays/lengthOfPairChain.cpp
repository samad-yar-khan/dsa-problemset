#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-length-of-pair-chain/

int findLongestChain(vector<vector<int>>& pairs) {
        for(int i =0;i<pairs.size();i++){
            swap(pairs[i][0],pairs[i][1]);
        }
        sort(pairs.begin(),pairs.end());
        int ce = pairs[0][0];
        int ans = 1;
        for(int i =1;i<pairs.size();i++){
            if(pairs[i][1]>ce){
                ce = max(ce,pairs[i][0]);
                ans++;
            }
        }
        for(int i =0;i<pairs.size();i++){
            swap(pairs[i][0],pairs[i][1]);
        }
        return ans;
        
    }
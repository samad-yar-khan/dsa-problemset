#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/node-with-highest-edge-score/
 int edgeScore(vector<int>& edges) {
        vector<long long> sumsScores(edges.size(),0);
        pair<int,long long>ans(10000000,0);
        for(int i =0;i<edges.size();i++){
            sumsScores[edges[i]] +=i;
            if(sumsScores[edges[i]] == ans.second && edges[i] < ans.first  ){
                ans = make_pair(edges[i], sumsScores[edges[i]]); 
            }
            if(sumsScores[edges[i]] > ans.second){
                ans = make_pair(edges[i], sumsScores[edges[i]]); 
            }
        }
        return ans.first;
    }
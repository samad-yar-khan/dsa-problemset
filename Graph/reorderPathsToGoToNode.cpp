#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
 int minReorder(int n, vector<vector<int>>& connections) {
        int N = connections.size();
        
        vector<vector<int>>out(n, vector<int>(0));
        vector<vector<int>>in(n, vector<int>(0));
        for(int i =0;i<N;i++){
            int a=connections[i][0];
            int b=connections[i][1];
            out[a].push_back(b);
            in[b].push_back(a);
        }
        
        vector<int>v(n,0);
        queue<int>q;
        q.push(0);
        v[0] = 1;
        int ans=0;
        
        while(q.size()){
            int f = q.front();q.pop();
            for(int i=0;i<in[f].size();i++){
                if(!v[in[f][i]]){
                    q.push(in[f][i]);
                    v[in[f][i]]=true;
                }
            }
             for(int i=0;i<out[f].size();i++){
                if(!v[out[f][i]]){
                    q.push(out[f][i]);
                    v[out[f][i]]=true;
                    ans++;
                }
            }
        }
        return ans;
    }
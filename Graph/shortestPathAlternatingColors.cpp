#include<bits/stdc++.h>
using namespace std;

//Shortest Path with Alternating Colors
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n,-1);
        vector<vector<vector<int>>>g(n,vector<vector<int>>(n,vector<int>(2,0)));
        for(int i =0;i<redEdges.size();i++){
            g[redEdges[i][0]][redEdges[i][1]][0] = 1; 
        }
        for(int i =0;i<blueEdges.size();i++){
            g[blueEdges[i][0]][blueEdges[i][1]][1] = 1; 
        }
        queue<pair<int,pair<int,int>>>q;
        vector<vector<bool>>vis(n,vector<bool>(2,0));
        q.push({0,{0,0}}); // node, from_path, len
        q.push({0,{1,0}}); // node, from_path, len
        vis[0][0] = 1;
        vis[0][1] = 1;
        while(q.size()){
            pair<int,pair<int,int>> t = q.front(); q.pop();
            int node =  t.first;
            int from = t.second.first;
            int len = t.second.second;
            if(ans[node] == -1){
                ans[node] = len;
            }   
            for(int i =0;i<n;i++){
                if(g[node][i][!from] && !vis[i][!from]){
                    q.push({i,{!from,len+1}});
                    vis[i][!from] = true;
                }
                
            }
        }
        return ans;
    }
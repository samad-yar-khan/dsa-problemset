#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
//do a dfs, as soon as you visit a apple, return the node (i.e. = 1)
    //when we return a +ve value from a child node, we also add to it as we have found an apple in our children
    //we subtract -1 from ans to remove the roots effect and now we double the node count
    //this will be the min path count
    int dfs(vector<vector<int>>&g, vector<bool>&vis, int ci, vector<bool>& ha){
        if(vis[ci]){
            return 0;
        }
        vis[ci] = true;
        int ans =0;
        for(int i=0;i<g[ci].size();i++){
            if(vis[g[ci][i]]){
                continue;
            }
            ans += dfs(g,vis,g[ci][i],ha);
        }
        if(ha[ci] || ans>0){
            ans+=1;
        }
        return ans;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> g(n+1,vector<int>(0));
        vector<bool>vis(n+1,false);
        for(int i =0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int ans = dfs(g,vis,0,hasApple);
        ans-=1;
        
        return max(ans*2,0);
        
    }
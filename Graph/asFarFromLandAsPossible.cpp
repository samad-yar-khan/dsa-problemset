#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/as-far-from-land-as-possible/

int maxDistance(vector<vector<int>>& grid) {
        int ans = -1;
        queue<pair<int,pair<int,int>>>q;
        int m =grid.size();
        if(!m){
            return -1;
        }
         int n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,0));
       
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({0,{i,j}});
                    vis[i][j] = 1;
                }
            }
        }
        if(q.size() == 0 || q.size() == m*n){
            return -1;
        }
        int X[4] = {0,0,-1,1};
        int Y[4] = {1,-1,0,0};
        while(q.size()){
            pair<int,pair<int,int>>t = q.front();q.pop();
            int dis  = t.first;
            int x = t.second.first;
            int y = t.second.second;
            ans = max(ans,dis);
            for(int i =0;i<4;i++){
                int x_ = x+X[i];
                int y_ = y+Y[i];
                if(x_>=0 && y_>=0 && x_<n && y_<m && !vis[x_][y_] && grid[x_][y_] == 0){
                    vis[x_][y_] = true;
                    q.push({dis+abs(y-y_)+abs(x-x_),{x_,y_}});
                }
            }
        }
        return ans;
    }
#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/rotting-oranges/submissions/
    int X[4] = {0,0,1,-1};
    int Y[4] = {-1,1,0,0};
    int orangesRotting(vector<vector<int>>& grid) {
       
        queue<pair<int,pair<int,int>>>pn;
        int n = grid.size();
        int m = grid[0].size();
        int riped =0;
         vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i = 0 ; i < n ; i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 2){
                    pn.push(make_pair(2,make_pair(i,j)));
                    vis[i][j] = true;
                }else if(grid[i][j] == 1){
                    riped++;
                }
            }
        }
        if(riped == 0){
            return 0;
        }
        if(pn.size()){
            pn.push({-1,{0,0}});
        }
        int ans =0;
        while(!pn.empty()){
            pair<int,pair<int,int>>t = pn.front(); pn.pop();
            int state = t.first;
            int x = t.second.first;
            int y = t.second.second;
            if(state == -1){
                if(pn.size() > 0){
                    pn.push(make_pair(-1,make_pair(x+1,y+1)));
                }else{
                    ans = x;
                }
            }else{
                for(int i =0;i<4;i++){
                    int x_ = x+X[i];
                    int y_ = y+Y[i];
                    if(x_>=0 && x_<n && y_>=0 && y_<m && grid[x_][y_] == 1 && !vis[x_][y_]){
                        pn.push({2,{x_,y_}});
                        grid[x_][y_] = 2;
                        vis[x_][y_] = true;
                        riped--;
                    }
                }
            }
        }
        return riped==0?ans:-1;
    }
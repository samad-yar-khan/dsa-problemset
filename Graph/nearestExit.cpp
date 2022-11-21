#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/submissions/
    int X[4] = {0,0,-1,1};
    int Y[4] = {-1,1,0,0};
    
    bool is_border(int x, int y, int m, int n, vector<int>entrance){
        if(x==entrance[0] && y== entrance[1]) return false;
        return ((x==0 || y==0 || x == m-1 || y==n-1));
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m= maze.size();
        int n = maze[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<int,pair<int,int>>>pn;
        pn.push(make_pair(0,make_pair(entrance[0],entrance[1])));
        vis[entrance[0]][entrance[1]] = true;
        
        while(pn.size()){
            pair<int,pair<int,int>>tn = pn.front();pn.pop();
            int dis = tn.first;
            for(int i =0;i<4;i++){
                int X_ = X[i] + tn.second.first;
                int Y_ = Y[i] + tn.second.second;
                if(X_ >= m || Y_ >=n || X_< 0 || Y_<0 || vis[X_][Y_] || maze[X_][Y_] == '+'){
                    continue;
                }
                if(is_border(X_,Y_,m,n,entrance)){
                    return dis+1;
                }
                vis[X_][Y_] = true;
                pn.push(make_pair(dis+1,make_pair(X_,Y_)));
            }
            
        }
        return -1;
        
    }
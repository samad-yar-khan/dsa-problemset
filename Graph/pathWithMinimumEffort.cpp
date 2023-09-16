#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/path-with-minimum-effort/
    
    int xm[4] = {0,0,-1,1};
    int ym[4] = {-1,1,0,0};
    
    int is_valid_coordinate(int i, int j , int rows, int cols){
        return i>=0 && i<rows && j>=0 && j<cols;
    }

    
    int effort(int i1, int j1, int i2, int j2, vector<vector<int>>&hts){
        int rows = hts.size();
        int cols = hts[0].size();
        if(!is_valid_coordinate(i1,j1, rows, cols)){
            return INT_MAX;
        }
        if(!is_valid_coordinate(i2,j2, rows, cols)){
            return INT_MAX;
        }
        return abs(hts[i1][j1] - hts[i2][j2]);
    }
    
    int minimumEffortPath(vector<vector<int>>& hts) {
        int rows = hts.size();
        int cols = hts[0].size();
        vector<vector<int>>efforts(rows, vector<int>(cols,INT_MAX));
        efforts[0][0] = 0;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<bool>>vis(rows, vector<bool>(cols,false));
        
        pq.push({0,{0,0}});
        
        while(pq.size()){
            
            pair<int,pair<int,int>>t = pq.top();pq.pop();
            
            int val = t.first;
            int x = t.second.first;
            int y = t.second.second;
            
            if(vis[x][y]){
                continue;
            }
            vis[x][y] = true;
            
            for(int i =0;i<4;i++){
                
                int x_ = x+xm[i];
                int y_ = y+ym[i];
                
                if(!is_valid_coordinate(x_,y_, rows, cols)){
                    continue;
                }
                if(vis[x_][y_]){
                    continue;
                }
                
                int new_effort = max(effort(x,y,x_,y_,hts),efforts[x][y]);
                if(new_effort < efforts[x_][y_]){
                    efforts[x_][y_] = new_effort;
                    pq.push({new_effort,{x_,y_}});
                }
            }
            
        }
       
        return efforts[rows-1][cols-1];
    }
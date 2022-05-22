#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/shortest-path-in-binary-matrix/
//shortest path always take bfs

    int X[8] = {-1,-1,0,1,1,1,0,-1};
    int Y[8] = {0,1,1,1,0,-1,-1,-1};
   
     bool pathExist (vector<vector<int>>&mat,vector<vector<bool>>&down,int i, int j, int n){
        if(i<0 || j <0 || j>=n || i>=n){
            return false; 
        }
        if(mat[i][j] == 1 || down[i][j]){
            return false;
        }
        return true;
    }
    
    int bfs(vector<vector<int>>& grid,vector<vector<bool>>&vis,int i,int j,int n){
        
        queue<pair<pair<int,int>,int>>pn;
        pn.push(make_pair(make_pair(0,0),1));
        vis[0][0] = true;
        while(pn.size()){
            pair<pair<int,int>,int> t = pn.front();
            pn.pop();
            if(t.first.first == n-1 && t.first.second == n-1){
                return t.second;
            }
           
            for(int itr = 0 ;itr < 8 ; itr++){
                int x = X[itr] + t.first.first;
                int y = Y[itr] + t.first.second;
                if(pathExist(grid,vis,x,y,n)){
                    vis[x][y] = true;
                    pn.push(make_pair(make_pair(x,y),t.second+1));
                }
            }
        }
        return -1;
       
    }
   

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(n==0){
            return -1;
        }
       
        if(grid[0][0] || grid[n-1][n-1]){
            return -1;
        }
       
        vector<vector<bool>> vis(n,vector<bool>(n,false));
         int ans = bfs(grid,vis,0,0,n);
       
      
        return ans;
        
        
    }
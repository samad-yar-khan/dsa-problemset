#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shortest-bridge/
//https://binarysearch.com/problems/Shortest-Bridge

/*
    mark one island with different intiger and use multisource bfs
*/

int solve(vector<vector<int>>& matrix) {
    int x=-1,y=-1;
    int r = matrix.size();
    int c = matrix[0].size();
    for(int i =0;i<r;i++){
        for(int j =0;j<c;j++){
            if(matrix[i][j]==1){
                x=i;
                y=j;
                break;
            }
        }
        if(x!=-1){
            break;
        }
    }

    queue<pair<int,int>>pn;
    int X[4] = {0,0,-1,1};
    int Y[4] = {-1,1,0,0};
    pn.push(make_pair(x,y));
    vector<vector<bool>>vis(r,vector<bool>(c,false));
    while(pn.size() > 0){

        pair<int,int>pp=pn.front();
      
        pn.pop();
        vis[pp.first][pp.second]=true;
        matrix[pp.first][pp.second] = 2;
        for(int i = 0 ; i < 4 ;i++){
            int x_ = X[i] + pp.first;
            int y_ = Y[i] + pp.second;

            if(x_ < 0 || y_ < 0 || x_ >= r || y_ >= c){
                continue;
            }
            if(vis[x_][y_]){
                continue;
            }
            if(matrix[x_][y_] != 1){
                continue;
            }
          
            if(!vis[x_][y_]){
                pn.push(make_pair(x_,y_));
            }
            vis[x_][y_]=true;  
        }
    }
    for(int i =0;i<r;i++){
        for(int j =0;j<c ;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

     vector<vector<bool>>v(r,vector<bool>(c,false));
    
     queue<pair<pair<int,int>,int>>p;
     int ans =INT_MAX;
       for(int i =0;i<r;i++){
        for(int j =0;j<c ;j++){
            if(matrix[i][j] == 2){
                v[i][j] = true;
                p.push(make_pair(make_pair(i,j),0));
            }
        }
        
    }
   
     while(!p.empty()){

        pair<pair<int,int>,int>t=p.front();
        p.pop();
        int a = t.first.first;
        int b = t.first.second;
        int d = t.second;

        for(int i = 0 ; i < 4 ;i++){
            int x_ = X[i] + a;
            int y_ = Y[i] + b;

            if(x_ < 0 || y_ < 0 || x_ >= r || y_ >= c){
                continue;
            }
            if(v[x_][y_]){
                continue;
            }
            if(matrix[x_][y_] == 1){
                ans=min(ans , d);
                continue;
            }
          
            if(!v[x_][y_] && matrix[x_][y_] == 2) {
                p.push(make_pair(make_pair(x_,y_),d));
                  v[x_][y_]=true;  
                continue;
            }

            if(!v[x_][y_] && matrix[x_][y_] == 0) {
                 p.push(make_pair(make_pair(x_,y_),d+1));
                   v[x_][y_]=true;  
                continue;
            }

          
        }

     }
    


    return ans;
}

#include<bits/stdc++.h>
using namespace std;

//https://binarysearch.com/problems/Number-of-Moves-to-Capture-the-King

int solve(vector<vector<int>>& board) {
    int n = board.size();
    int X[] = {-2,-1,-2,-1,2,1,2,1};
    int Y[] = {1,2,-1,-2,-1,-2,1,2};
    queue<pair<int,pair<int,int>>>pn;
    bool breakLoop =false;
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            if(board[i][j] ==2){
                pn.push(make_pair(0,make_pair(i,j)));
                breakLoop = true;
                vis[i][j] = true;            
                break;
            }
        }
        if(breakLoop){
            break;
        }
    }
    int ans =0;
   
    while(pn.size()){

        pair<int,pair<int,int>>p=pn.front();
        pn.pop();
        int x=p.second.first;
        int y=p.second.second;
        int dis = p.first;
        if(board[x][y] == 1){
            return dis;
        }
        for( int i =0;i<8;i++){
            int xx = x+X[i];
            int yy = y+Y[i];

            if(xx<0 || xx>=n || yy>=n || yy<0){
                continue;
            }
            if(vis[xx][yy]){
                continue;
            }
            vis[xx][yy] = true;
            pn.push(make_pair(dis+1,make_pair(xx,yy)));
        }

    }
    return -1;

}
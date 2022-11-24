#include<bits/stdc++.h>
using namespace std;

    // https://leetcode.com/problems/word-search/
    int X[4] = {-1,1,0,0};
    int Y[4] = {0,0,-1,1};
    
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, string &word, int wi, int x, int y ){
        if(wi>=word.length()){
            return true;
        }
        if(x >= board.size() || y >= board[0].size() || x < 0 || y < 0){
            return false;
        }
        if(vis[x][y]){
            return false;
        }
        if(board[x][y] != word[wi]){
            return false;
        }
        vis[x][y] = true;
        for(int i =0;i<4;i++){
            if(dfs(board, vis, word, wi+1, x+X[i],y+Y[i])){
                vis[x][y] = false;
                return true;
            }
        }
        vis[x][y] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>vis(board.size(),vector<bool>(board[0].size(),0));
        for(int i =0;i<board.size();i++){
            for(int j =0;j<board[0].size();j++){
                if(word[0] == board[i][j]){
                    if(dfs(board,vis,word,0,i,j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
//https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

#include<bits/stdc++.h>
using namespace std;

    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int rows = grid.size();
        // if(rows == 0){
        //     return -1;
        // }
        int cols = grid[0].size();
        // if(cols == 0){
        //     return -1;
        // }
        queue<pair<int , int>*> t;
        
        int x[8] = {-1,0,0,1};
        int y[8] = {0,-1,1,0};
        
        for(int i = 0 ; i <rows ; i++){
            for(int j = 0 ; j < cols; j++){
                
                if(grid[i][j] == 0 || grid[i][j] == 1){
                    continue;
                }
                
                pair<int,int> *p = new pair<int , int>;
                p->first = i;
                p->second = j;
              
                t.push(p);
                        
            }
        }
        pair<int , int>* delim = new pair<int , int>;
        delim->first = -1;
        delim->second = 0;
        t.push(delim);
        int _time = 0 ;
        while(!t.empty()){
            pair<int , int> *top = t.front();
            t.pop();
            // cout<<top->first <<" "<<top->second;
                
            //delim
            if(top->first == -1){
                if(t.size() == 0){
                   
                    _time = top->second;
                    break;
                }else{
                   
                    pair<int , int>* n = new pair<int, int>;
                    n->first = -1;
                    n->second = top->second + 1;
                    // cout<<n->first<<" "<<n->second;
                    t.push(n);
                    continue;
                }
            }
            
            
            //check
            for(int i = 0 ; i < 4 ; i++){
                int X = top->first + x[i];
                int Y = top->second + y[i];
                
                
                 if(X <0 || X>=rows|| Y <0 || Y>=cols){
                    continue;
                }
                        
                if(grid[X][Y] == 2 || grid[X][Y] == 0){
                    continue;
                }
                
                grid[X][Y] = 2;//wrotten now
                  pair<int,int> *p = new pair<int , int>;
                  p->first = X;
                  p->second = Y;
                  t.push(p);
                        
            }
            delete top;
        }
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ;  j < cols ; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return _time;
        
        
    }
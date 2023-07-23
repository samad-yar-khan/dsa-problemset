#include <bits/stdc++.h>
using namespace std;

    int moves[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, -1}, {-2, 1}};
    double cell_selection_probability = 0.125;
    double one = 1;
    
    bool is_out_of_board(int x, int y, int n){
        return x < 0 || y< 0 || x >= n || y>= n;
    }
    
    double knightProbability_moving_out(vector<vector<vector<double>>>&probability_going_out, int x, int y, int n, int k){  
        if(is_out_of_board(x,y,n)){
            return one;
        }
        if(k<=0){
            return 0;
        }
        if(probability_going_out[k][x][y]!=-1){
            return probability_going_out[k][x][y];
        }
        
        double probability_going_out_from_current_cell = 0;
        
        for(int i =0;i<8;i++){
            
            double probability_going_out_following_move = (cell_selection_probability*knightProbability_moving_out(probability_going_out,x+moves[i][0],y+moves[i][1],n,k-1));
            
            probability_going_out_from_current_cell+=probability_going_out_following_move;
            
        }
        
        probability_going_out[k][x][y] = probability_going_out_from_current_cell;
        
        return probability_going_out_from_current_cell;
        
    }
    
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<vector<double>>>probability_going_out(k+1,vector<vector<double>>(n,vector<double>(n,-1)));
        
        return one- knightProbability_moving_out(probability_going_out, row, column,n, k);
      
    }
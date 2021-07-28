#include<iostream>
#include <vector>
#include<cmath>
using namespace std;

void printGrid (int grid[][9]) 
    {
        // Your code here 
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }    
    }

bool canPlace(int number , int grid[][9] , int row , int col){
    //chek col
    for(int i = 0 ; i < 9 ; i++){
        if(grid[i][col] == number || grid[row][i] == number){
            return false;
        }
    }

    // check row
 

    //now we must check grid
    // so starting pts of gid are given by ((row/3)*3 , (col/3)*3)
    int sub_grid_x = (row/3)*3;
    int sub_grid_y = (col/3)*3;

    for(int i = sub_grid_x ; i < sub_grid_x+3 ; i++){
        for(int j = sub_grid_y ; j <sub_grid_y +3 ; j++){

            if(grid[i][j] == number){
                return false;
            }

        }
    }

    return true;


}

bool sudokuSolver(int grid[][9] , int row , int col ){

    if(row >=  9 ){
        printGrid(grid);
        return true ; //sedoku solved
    }

    //if we have to go the next row
    if(col >= 9){

        return sudokuSolver(grid , row+ 1 , 0);

    }   
    //if place is already filled
    if(grid[row][col] != 0){
        return sudokuSolver(grid , row , col+1);
    }

    //now if we have an emprt place , we need to fill number sbetween 1 to 9 but we check that the number 
    //should not exist in the row or col or in the subgrid

    for(int num = 1 ; num <= 9 ; num++){
        if(canPlace(num , grid , row , col)){
            grid[row][col] = num; //set number assuming it give sthe rigghht ans
            bool solved = sudokuSolver(grid , row , col+1);
            if(solved){
                return true;//no need to check further
            }
            //if not solved we must try the next possible number
             grid[row][col] = 0;
        }
    }

    //backtracked 
    //if we are here that means none of our combination worked so we must go back and reset prev number
    return false;



}

 bool SolveSudoku(int grid[9][9])  
    { 
        return sudokuSolver(grid , 0 , 0);
    }

	// int main(){
	// 	int n = 0 ;
	// 	cin>>n;
	// 	int grid[9][9];

	// 	for(int i = 0 ; i  < 9 ;  i++){
	// 		for(int j = 0 ; j < 9 ; j++){
	// 			cin>>grid[i][j];
	// 		}
	// 	}

	// 	SolveSudoku(grid);  
	// 	return 0;
	// }
    // //Function to print grids of the Sudoku.

int main(){
    int grid[9][9] = {
        {0 , 9 , 1 , 0 , 0, 0, 5,0 , 0  },
        {0 , 0 , 0 , 1 , 6, 0, 0,9 , 2  },
        {3 , 0 , 0 , 0 , 0, 9, 1,0 , 0  },
        {0 , 0 , 0 , 0 , 1, 0, 0,0 , 7  },
        {4 , 8 , 5 , 0 , 0, 0, 9,3 , 1  },
        {1 , 0 , 0 , 0 , 8, 0, 0,0 , 0  },
        {0 , 0 , 9 , 4 , 0, 0, 0,0 , 8  },
        {6 , 3 , 0 , 0 , 5, 8, 0,0 , 0  },
        {0 , 0 , 8 , 0 , 0, 0, 6,4 , 0  }
    };
    SolveSudoku(grid);
    printGrid(grid);


}

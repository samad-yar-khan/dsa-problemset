
#include<iostream>
#include<cmath>
#include<vector>
#define modVal 1000000007
#define ll long long
using namespace std;

   int findWays (int last_row, int last_col, vector<vector<int>> &maze ,  vector<vector<int>> &numPaths, int curr_row , int curr_col){
        
        //bc
        // cout<<curr_row<<" "<<curr_col<<'\n';
        if(last_col == curr_col && last_row == curr_row && maze[curr_row][curr_col] == 1 ){
            return 1; //one path found
        }
        //edge case
        if(curr_col > last_col || curr_row > last_row){
            return 0; //no path
        }
        if(maze.at(curr_row).at(curr_col) == 0){
            return 0;
        }

        //memoization case
        if(numPaths[curr_row][curr_col] != -1){
            return numPaths.at(curr_row).at(curr_col);
        }

        //ih
        int rightPath = findWays(last_row , last_col , maze , numPaths , curr_row  , curr_col +1 )%modVal;
        int downPath = findWays(last_row , last_col , maze , numPaths , curr_row +1  , curr_col  )%modVal;

        //is 
        numPaths.at(curr_row).at(curr_col) = (rightPath  + downPath)%modVal ;
        return numPaths.at(curr_row).at(curr_col);

    }
    
	int FindWays(int n, int m, vector<vector<int>>blocked_cells ){
	    // Code here
        vector<vector<int>> maze(n , vector<int>(m , 1)) ; // we create  vector with n elements each being a vector of int

        //make the maze
        for(long long i = 0 ; i < blocked_cells.size() ; i++){
            maze.at(blocked_cells[i][0]-1).at(blocked_cells[i][1]-1) = 0;
        }   

        //now we need an answer matrix to save a our no of paths for each cell
        vector<vector<int>> numPaths(n , vector<int>(m , -1)) ;

        int ans = findWays(n-1 , m-1 , maze , numPaths , 0 , 0);
        return ans;
	    
	}

    int main(){

        int n = 0 , m= 0 , k = 0 ;
        cin>>n>>m>>k;

        vector<vector<int>> vec(k);
        for(int i = 0 ; i < k ; i++){
            for(int j = 0 ; j < 2 ; j++){
                int a = 0 ;
                cin>>a;
                vec.at(i).push_back(a);
            }
        }

        cout<<FindWays(n,m ,vec);

    }
#include <iostream>
using namespace std;

/*
https://online.codingblocks.com/app/player/200364/content/186838/4927/code-challenge

You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from position (i,j), down or right on the grid.
Initially rat is on the position (1,1). It wants to reach position (N,M). Find the rightmost path through which, rat can reach this position. A path is rightmost, if the rat is at position (i,j), it will always move to (i,j+1), if there exists a path from (i,j+1) to (N,M).

Input Format
First line contains 2 integers, N and M, denoting the rows and columns in the grid. Next N line contains. M characters each. An 'X' in position (i,j) denotes that the cell is blocked and ans 'O' denotes that the cell is empty.

Constraints
1<=N,M<=1000 GRID(i,j)='X' or 'O'

Output Format
If a solution exists: Print N lines, containing M integers each. A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path and a 0 denotes that the cell is not covered in the path.
If solution doesn't exist, just print "-1".

Sample Input
5 4
OXOO
OOOX
OOXO
XOOO
XXOO
Sample Output
1 0 0 0 
1 1 0 0 
0 1 0 0 
0 1 1 1 
0 0 0 1 
*/

bool  printPath(int m , int n , int**path , char**mat , int x , int y){

    //base case
    if(x == m && y == n && mat[x][y] != 'X'){
		path[x][y] = 1;
        for(int i = 0 ; i <= m ; i++){
            for(int j =  0 ; j <=  n ; j++){
                cout<<path[i][j]<<" ";
            }
            cout<<"\n";
        }
        return true;
    }   
    //edge case
    if(x > m ||  y >n){
        return false;
    }
    if(mat[x][y] == 'X'){
        return false;
    }

    //is
    path[x][y] = 1;


    //ih


    bool rightPath = printPath( m , n , path , mat , x , y+1 );
    bool downPath = false;
    if(rightPath == false){
        downPath = printPath(m , n , path , mat ,x+1 , y);
    }
 
   

    //backtack
    path[x][y] = 0;
    return downPath||rightPath;

}

int main(){

    int m =  0 , n = 0;
    cin>>m>>n;

    char**mat = new char*[m];
    for(int i = 0 ; i < m ; i++){
        mat[i] = new char[n];
        for(int j =  0 ; j <  n ; j++){
            mat[i][j] = '\0';
        }
    }

    for(int i = 0 ; i < m ; i++){
        for(int j =  0 ; j <  n ; j++){
            cin>>mat[i][j];
        }
    }

    int**path = new int*[m];
    for(int i = 0 ; i < m ; i++){
        path[i] = new int[n];
        for(int j =  0 ; j <  n ; j++){
            path[i][j] = 0;
        }
    }

    bool a = printPath(m-1 , n-1 , path,mat ,0,0);
	if(!a){
		cout<<-1<<"\n";
	}
   
    for(int i = 0 ; i < m ; i++){
        delete [] mat[i];
        delete [] path[i];
    }

    delete [] path;
    delete [] mat;

    return  0;
}
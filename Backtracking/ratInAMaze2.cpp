#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

/*
https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

Rat in a Maze Problem - I 
Medium Accuracy: 37.73% Submissions: 64308 Points: 4
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
*/

 bool paths( vector<vector<int>> &m , int**visited , int n , string s , int x , int y  , vector<string> & ans){
    
        //bc 
        if(x == n-1 && y == n-1 && m[x][y] == 1){
            
            ans.push_back(s);
            return true;
         
        }
        
        //edge case
        if( x >= n || y >= n || x<0 || y <0 || visited[x][y]){
            return false;
        }
        
        if(m[x][y] == 0){
            return false;
        }
        
        visited[x][y] = 1;
        
        bool goingUp = paths(m , visited , n , s+"U", x-1 , y , ans);
        bool goingRight = paths(m , visited , n , s+"R", x , y+1 , ans);
        bool goingLeft  = paths(m , visited , n , s+"L", x , y-1 , ans);
        bool goingDown = paths(m , visited , n , s+ "D", x+1 , y , ans);
        
        //clear the path
         visited[x][y] = 0;
         
         return goingUp|| goingRight|| goingLeft|| goingDown;
        
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        string s ="";
        
        int**visited = new int*[n];
        for(int i = 0 ; i < n ; i++){
            visited[i] = new int[n];
            for(int j =  0 ; j <  n ; j++){
                visited[i][j] = 0;
            }
        }
        
        vector<string> ans ;
        
        bool exists = paths(m , visited , n , s , 0, 0 , ans);
        
        sort(ans.begin() , ans.end());
        for(int i = 0 ; i < n ;i++){
            delete [] visited[i];
        }
        
        
        delete [] visited ;
        return ans;
    }
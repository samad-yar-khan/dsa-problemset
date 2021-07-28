#include<bits/stdc++.h>
using namespace std;


/*
oid visit (int** edges , int n , int SI , bool* visited ){
    visited[SI] = true ;
    
    for(int i = 0 ; i < n ; i++){
        if(visited[i] || i==SI){
            continue;
        }
        if(edges[SI][i] == 1){
                visit(edges , n , i , visited);
        }
    }
    return ;
}
void visit_iterative(int** edges , int n , int SI , bool* visited ){
    
    queue<int> pending;
    pending.push(SI);
    visited[SI] = true;

    while(!pending.empty()){

        int c = pending.front();
        pending.pop();
        for(int i = 0 ; i <  n ; i++){
            if( c==i || visited[i] ){
                continue;
            }
            if(edges[c][i] == 1){
                visited[i] = true;
                pending.push(i);
            }
        }
    }

}


int solve(int n,int m,vector<int>u,vector<int>v)
{

    //i need to have a ,map of my islands to know what are my components 
    //and which islands are connected and which arent 
    //for this we are gonna use an adjacency matrix 
    //and keep track of island groups

    int**edges = new int*[n];
    for(int i=0 ; i < n ; i++){
        edges[i] = new int[n];
        for(int j{0} ; j < n ; j++ ){
            
            edges[i][j] = 0 ; //no paths / islabns connected till now

        }
    }

    for(int i{0} ; i < m ; i++){
        int x = 0 ; 
        int y = 0 ;

        x = u[i];
        y = v[i]; //we have one set of cordinates x and y now 

        //now the values in the lists u and i starts from 1 and go to N
        //but our indices of adacency matric go from 0 to N-1
        //so if we are given that we have island 1  connected to  island 2
        //we can interpret this as island 0 to connecte to island 1 
        //and this wont change our results
        x-=1; //reason mentioned above 
        y-=1;

        edges[x][y] = 1; //island are connected bothw ways
        edges[y][x] = 1; //in reality island x+1 is connected to island y+1 and vice versa

    }

    bool*visited = new bool[n];
    for(int i{0} ; i<n ; i++){
        visited[i] =  false; //not visited till now 
    }

    //we need to make a function wehch tells us how many visits are needs to the islad region to go through 
    //all the island 
    //suppose i take  a fligjt to island 1 so i can travel to all other island  by car and dont need any more
    //flight tickets ,but if a certain group is disn=conneced we ll take flight to one pf the islands 
    //in that group and then travel the whoe region by car
    int tickets = 0 ;
    for(int i = 0 ; i < n ; i++){

        if(!visited[i]){
            visit_iterative(edges , n , i , visited);
            tickets+=1;
        }
    }
    
    for(int i{0} ; i < n ; i++){
        delete[] edges[i];
    }    
    delete [] edges;
    return tickets;
}
*/

// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1#
int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        queue<pair<int , int>> islands ;
         bool**visited = new bool*[grid.size()];
    for(int i = 0 ; i <  grid.size(); i++){
        visited[i] = new bool [grid[0].size()];
        for(int j = 0  ; j < grid[0].size() ; j++){
            visited[i][j] = false ; //no edges between i and j
        }
    }
    
      
        int a  = 0 ;
        
        int x[8] = {-1,-1,-1,0,0,1,1,1};
        int y[8] = {-1,0,1,-1,1,-1,0,1};
        
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                
                if(visited[i][j] || grid[i][j] != '1') {
                    continue;
                }
                
                visited[i][j] = true;
                a++;
                queue<pair<int , int>> islands ;
                pair<int , int> p(i,j);
            //   cout<<i<<"-"<<j<<" ";
                islands.push(p);
                
                while(islands.size() > 0){
                   
                    pair<int , int> pt = islands.front();
                    islands.pop();
                    
                    for(int k = 0 ;k < 8 ; k++){
                        int X = x[k] + pt.first;
                        int Y = y[k] + pt.second;
                        
                        if(X <0 || X>=grid.size() || Y <0 || Y>=grid[i].size()){
                            continue;
                        }
                        
                        if(visited[X][Y] ||  grid[X][Y] != '1') {
                            continue;
                        }
                        
                        visited[X][Y] = true;
                        pair<int,int> nearBy(X,Y);
                        islands.push(nearBy);
                    }
                    
                }
                
            }
        }
        
         for(int i = 0 ; i <  grid.size()  ; i++){
        delete [] visited[i];

    }
    delete [] visited;
    
        return a;
    }
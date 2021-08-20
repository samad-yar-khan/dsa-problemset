#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1#

/*
as we have been givne the min path ad we can go in all direction we cant really use dp beause it  wont give teh req ans as the path can be any
here we use the djaktras algo for min path and use  pq to ggte the min node eahc time 
to use the pq we can use a custom coparator class

*/
    // class edge
    // {

    //     int wt ;
    //     int x ;
    //     int y ;



    // };
    class compare{

        public :

        bool operator()(pair<int , pair<int , int> >a,pair<int , pair<int , int> > b ){
            return (a.first > b.first);
        }
    };

    
    pair<int , pair<int , int> >makeObj(int wt , int x , int y){
        pair<int , int > co(x,y);
        pair<int, pair<int , int>> ans;
        ans.first = wt;
        ans.second = co;
        return ans;
    }
    
    int djakstra(vector<vector<int>> &grid , int minCost[500][500] , bool visited[500][500] ,  int n ){
            
        priority_queue<pair<int , pair<int , int> >  , vector<pair<int , pair<int , int> >> , compare> pq;
        minCost[0][0] = grid[0][0];
        
        pq.push(makeObj(grid[0][0] , 0,0));
        
        int countNodes = 0 ;
        int X[4] = {-1,1,0,0};
        int Y[4] = {0,0,-1,1};
       
        while(countNodes<(n*n) && pq.size() > 0){
            
            pair<int  , pair<int , int >>minNode = pq.top();
            pq.pop();
            int wt = minNode.first;
            int x = minNode.second.first;
            int y = minNode.second.second;
            // cout<<x<<" "<<y<<" "<<wt<<"\n";
            if(visited[x][y]){//if already vis
                continue;
            }
            
            visited[x][y] = true;

            // cout<<x<<"---"<<y<<"\n";
            for(int i = 0 ;i < 4 ; i++){
                int X_ = x + X[i];
                int Y_ = y + Y[i];

               
                if(X_ >=  n || Y_ >=n  || X_<0 || Y_<0){
                    continue ;
                }

                if(visited[X_][Y_]){
                    continue;
                }
             
                //get min path
                if(minCost[X_][Y_] > wt + grid[X_][Y_]){
                    // cout<<X_<<" "<<Y_<<"\n";
                    minCost[X_][Y_]=  wt + grid[X_][Y_];
                    pq.push(makeObj(minCost[X_][Y_] , X_ , Y_));
                }
                
            }
          
            countNodes ++;
        }

        
        return minCost[n-1][n-1];
        
    }

	
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        int minCost[500][500];
        bool visited[500][500];
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                minCost[i][j] = INT_MAX;
                visited[i][j] = false;   
            }
        }
        
        int ans = djakstra(grid , minCost , visited , n );
        return ans;
        
    }


    int main(){

        vector<vector<int>> grid;
        int n = 0 ;
        cin>>n;

        for(int i = 0 ; i < n ; i++){

            vector<int> row;
            for(int j =0; j< n ; j++){
                int a =0;
                cin>>a;
                row.push_back(a);
            }
            grid.push_back(row);
        }

        cout<<minimumCostPath(grid);


    }